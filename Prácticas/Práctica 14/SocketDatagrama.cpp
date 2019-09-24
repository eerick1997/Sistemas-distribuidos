#include "PaqueteDatagrama.h"
#include "SocketDatagrama.h"
#include <sys/socket.h>
#include <bits/stdc++.h>
#include <netinet/in.h>
#include <arpa/inet.h>

SocketDatagrama::SocketDatagrama(int port)
{
    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
}

int SocketDatagrama::envia(PaqueteDatagrama &p)
{
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

int SocketDatagrama::recibe(PaqueteDatagrama &p)
{
    char *datos;
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    unsigned int direccionForaneaLen;
    direccionForaneaLen = sizeof(direccionForanea);
    recvfrom(s, (char *)datos, 65507 * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &direccionForaneaLen);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(direccionForanea.sin_addr), ip, INET_ADDRSTRLEN);
    p.inicializaIp(ip);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    p.inicializaDatos(datos);
}