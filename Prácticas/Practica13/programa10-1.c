#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <strings.h>
#include <string.h>
#include <fcntl.h>  // for open
#include <unistd.h> // for close

int puerto = 7200;

int main(void)
{
   struct sockaddr_in msg_to_server_addr, client_addr;
   int s, num[2], res;

   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   msg_to_server_addr.sin_family = AF_INET;
   // msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
   msg_to_server_addr.sin_addr.s_addr = inet_addr("10.100.70.175");
   msg_to_server_addr.sin_port = htons(puerto);

   /* rellena la direcciòn del cliente*/
   bzero((char *)&client_addr, sizeof(client_addr));
   client_addr.sin_family = AF_INET;
   client_addr.sin_addr.s_addr = INADDR_ANY;

   /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
   client_addr.sin_port = htons(0);
   bind(s, (struct sockaddr *)&client_addr, sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *)&msg_to_server_addr, sizeof(msg_to_server_addr));

   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   char ip[INET_ADDRSTRLEN];
   inet_ntop(AF_INET, &(msg_to_server_addr.sin_addr), ip, INET_ADDRSTRLEN);
   // printf("%d\n", msg_to_server_addr.sin_addr.s_addr);
   // unsigned char new_buf[4];
   // memcpy(new_buf, &msg_to_server_addr.sin_addr.s_addr, 4);
   // printf("%x\n", *new_buf);
   printf("IP: %s\t|\tPORT: %d \n", ip, ntohs(msg_to_server_addr.sin_port));
   printf("2 + 5 = %d\n", res);
   close(s);
}
