#include "SocketMulticast.h"
#include "SocketDatagrama.h"
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
#include "Mensaje.h"

using namespace std;

unsigned int SocketMulticast::numMessage = 0;

SocketMulticast::SocketMulticast(int port)
{

    int reuse = 1;
    s = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (setsockopt(s, SOL_SOCKET, SO_REUSEPORT, &reuse, sizeof(reuse)) == -1)
    {
        printf("Error al llamar a la función setsockopt\n");
        exit(0);
    }
    bzero((char *)&direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = PF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(port);
    bind(s, (struct sockaddr *)&direccionLocal, sizeof(direccionLocal));
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
}

void SocketMulticast::unirseGrupo(char *IP)
{
    ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(IP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_ADD_MEMBERSHIP, (void *)&multicast, sizeof(multicast));
}

void SocketMulticast::salirseGrupo(char *IP)
{
    ip_mreq multicast;
    multicast.imr_multiaddr.s_addr = inet_addr(IP);
    multicast.imr_interface.s_addr = htonl(INADDR_ANY);
    setsockopt(s, IPPROTO_IP, IP_DROP_MEMBERSHIP, (void *)&multicast, sizeof(multicast));
}

int SocketMulticast::envia(PaqueteDatagrama &p, int TTL)
{
    direccionForanea.sin_family = PF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    int val = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&TTL, sizeof(TTL));
    return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

int SocketMulticast::recibe(PaqueteDatagrama &p)
{
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    socklen_t direccionForaneaLen = sizeof(direccionForanea);
    int tam = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof(char), 0, (struct sockaddr *)&direccionForanea, &direccionForaneaLen);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(direccionForanea.sin_addr.s_addr), ip, INET_ADDRSTRLEN);
    p.inicializaIp(ip);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    return tam;
}

int SocketMulticast::enviaConfiable(PaqueteDatagrama &p, int TTL, int num_receptores)
{
    direccionForanea.sin_family = PF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    int val = setsockopt(s, IPPROTO_IP, IP_MULTICAST_TTL, (void *)&TTL, sizeof(TTL));
    Mensaje MensajeNum;
    MensajeNum.messageId = numMessage;
    MensajeNum.messageType = DATA;
    memcpy(MensajeNum.datos, p.obtieneDatos(), p.obtieneLongitud());
    SocketDatagrama socketUni(8888);
    PaqueteDatagrama pAux(sizeof(unsigned int));
    int verify = 0;
    int tam = sendto(s, (char *)&MensajeNum, sizeof(Mensaje) * sizeof(char), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
    for (int j = 0; j < num_receptores; j++)
    {
        if (socketUni.recibeTimeout(pAux, 1, 50) > 0)
        {
            int numReceived;
            if (numReceived == numMessage)
            {
                verify += 1;
            }
        }
    }
    if (verify == num_receptores)
    {
        numMessage++;
    }
    else
    {
        tam = -1;
    }
    socketUni.~SocketDatagrama();
    pAux.~PaqueteDatagrama();
    return tam;
}

int SocketMulticast::recibeConfiable(PaqueteDatagrama &p)
{
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
    socklen_t direccionForaneaLen = sizeof(direccionForanea);
    Mensaje MensajeNumerado;
    int tam = recvfrom(s, (char *)&MensajeNumerado, sizeof(MensajeNumerado), 0, (struct sockaddr *)&direccionForanea, &direccionForaneaLen);
    char ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(direccionForanea.sin_addr.s_addr), ip, INET_ADDRSTRLEN);
    p.inicializaIp(ip);
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    p.inicializaDatos(MensajeNumerado.datos);
    SocketDatagrama socketUni(8888);
    PaqueteDatagrama pAux(sizeof(unsigned int));
    pAux.inicializaDatos((char *)&MensajeNumerado.messageId);
    pAux.inicializaIp(p.obtieneDireccion());
    pAux.inicializaPuerto(p.obtienePuerto());
    if (numMessage == MensajeNumerado.messageId)
    {
        numMessage++;
    }
    else
    {
        tam = -1;
    }
    socketUni.~SocketDatagrama();
    pAux.~PaqueteDatagrama();
    return tam;
}

SocketMulticast::~SocketMulticast()
{
    close(s);
}