#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <unistd.h> // for close
class SocketMulticast
{
public:
    SocketMulticast(int);
    ~SocketMulticast();
    int recibe(PaqueteDatagrama &p);
    int recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos);
    int envia(PaqueteDatagrama &p, unsigned char TTL);
    //Se une a un grupo multicast, recibe la IP multicast
    void unirseGrupo(char *);
    //Se sale de un grupo multicast, recibe la IP multicast
    void salirseGrupo(char *);

private:
    int s; //ID socket
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    timeval timeout;
};