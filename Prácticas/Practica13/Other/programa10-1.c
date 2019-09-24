#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

#include <unistd.h>
#include <arpa/inet.h>

int puerto = 7200;

int main(void)
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   unsigned long IP = 0;
   int residuo = 0;
   int s, num[2], res, i = 0;
   char copia[8];
   
   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   msg_to_server_addr.sin_port = htons(puerto);

   IP = msg_to_server_addr.sin_addr.s_addr;

   while( IP != 0 ){
      residuo = IP % 10;
      copia[ i++ ] = residuo + '0';
      IP /= 10;
   }

   for( int i = 7; i >= 0; i-- )
      printf( "%c ", copia[ i ] );
   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;
   
   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   printf("\n2 + 5 = %d\n", res);
   close(s);
}

