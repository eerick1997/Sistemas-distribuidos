#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <strings.h>

int puerto = 7200;

int main(void)
{
   int num[2];
   int s, res, clilen;
   struct sockaddr_in server_addr, msg_to_client_addr;

   s = socket(AF_INET, SOCK_DGRAM, 0);

   /* se asigna una direccion al socket del servidor*/
   bzero((char *)&server_addr, sizeof(server_addr));
   server_addr.sin_family = AF_INET;
   server_addr.sin_addr.s_addr = INADDR_ANY;
   server_addr.sin_port = htons(puerto);
   bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
   clilen = sizeof(msg_to_client_addr);
   while (1)
   {
      recvfrom(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
      //char* ip = msg_to_client_addr.sin_addr.s_addr;
      char ip[INET_ADDRSTRLEN];
      inet_ntop(AF_INET, &(msg_to_client_addr.sin_addr), ip, INET_ADDRSTRLEN);
      printf("IP: %s\t|\tPORT: %d \n", ip, ntohs(msg_to_client_addr.sin_port));
      res = num[0] + num[1];

      /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
      sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
   }
}
