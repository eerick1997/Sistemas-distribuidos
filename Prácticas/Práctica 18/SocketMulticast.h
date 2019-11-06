#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include "PaqueteDatagrama.h"
#ifndef _SOCKETMULTICAST_
#define _SOCKETMULTICAST_
class SocketMulticast
{
public:
    SocketMulticast(int);
    ~SocketMulticast();
    int recibe(PaqueteDatagrama &p);
    int envia(PaqueteDatagrama &p, int TTL);
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
#endif