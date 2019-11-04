#include "SocketMuilticast.h"
#include "PaqueteDatagrama.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

SocketMulticast::SocketMulticast(int port){

    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    cout << s << endl;
    int reuse = 1;

    if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1) {
        perror("Error al inicializar socket");
        exit(0);
    }
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons( port );
    auto n = bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
}

void SocketMulticast::unirseGrupo(char *IP){
    ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(IP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&multicast, sizeof(multicast));
}

void SocketMulticast::salirseGrupo(char *IP){
    ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(IP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *)&multicast, sizeof(multicast));
}

int SocketMulticast::envia(PaqueteDatagrama &p, int TTL){   
    setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, &TTL, sizeof(TTL));
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = PF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

int SocketMulticast::recibe(PaqueteDatagrama &p){
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    socklen_t direccionForaneaLen = sizeof(direccionForanea);
    int tam = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &direccionForaneaLen);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(direccionForanea.sin_addr), ip, INET_ADDRSTRLEN);
    p.inicializaIp(ip);
    p.inicializaPuerto((int)ntohs(direccionForanea.sin_port));
    return tam;
}

int SocketMulticast::recibeTimeout(PaqueteDatagrama &p, time_t segundos, suseconds_t microsegundos)
{
    timeout.tv_sec = segundos;
    timeout.tv_usec = microsegundos;
    setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
    char datos[p.obtieneLongitud()];
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    socklen_t direccionForaneaLen = sizeof(direccionForanea);
    int n = recvfrom(s, (char *)datos, p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &direccionForaneaLen);
    if (n < 0)
    {
        if (errno == EWOULDBLOCK)
        {
            fprintf(stderr, "Tiempo para recepción transcurrido\n");
        }
        else
        {
            fprintf(stderr, "Error en recvfrom\n");
        }
        n = -1;
    }
    else
    {
        char ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(direccionForanea.sin_addr), ip, INET_ADDRSTRLEN);
        p.inicializaIp(ip);
        p.inicializaPuerto((int)ntohs(direccionForanea.sin_port));
        p.inicializaDatos(datos);
    }
    //setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, NULL, 0);
    return n;
}

SocketMulticast::~SocketMulticast()
{
    close(s);
}