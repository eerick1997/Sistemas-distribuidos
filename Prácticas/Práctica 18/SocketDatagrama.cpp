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

using namespace std;

SocketDatagrama::SocketDatagrama( int port ) {
    s = socket( AF_INET, SOCK_DGRAM, 0 );
    bzero( (char *)&direccionLocal, sizeof( direccionLocal ) );
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons( port );
    bind(s, (struct sockaddr *)&direccionLocal, sizeof( direccionLocal ) );
    bzero((char *)&direccionForanea, sizeof(direccionForanea));
}

int SocketDatagrama::envia(PaqueteDatagrama &p) {
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr( p.obtieneDireccion() );
    direccionForanea.sin_port = htons( p.obtienePuerto() );
    return sendto(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof( int ), 0, (struct sockaddr *)&direccionForanea, sizeof(direccionForanea));
}

int SocketDatagrama::recibe(PaqueteDatagrama &p) {
    cout << "Recibe" << endl;
    socklen_t direccionForaneaLen = sizeof(direccionForanea);
    cout << "recvfrom " << endl;
    int tam = recvfrom(s, (char *)p.obtieneDatos(), p.obtieneLongitud() * sizeof( int ), 0, (struct sockaddr *)&direccionForanea, &direccionForaneaLen);
    cout << tam << endl;
    char ip[ INET_ADDRSTRLEN ];
    inet_ntop(AF_INET, &(direccionForanea.sin_addr.s_addr), ip, INET_ADDRSTRLEN);
    for( int i = 0; i < INET_ADDRSTRLEN; i++ )
        cout << ip[ i ] << " ";
    cout << endl;
    p.inicializaIp( ip );
    p.inicializaPuerto(ntohs(direccionForanea.sin_port));
    cout << "Port: " << ntohs( direccionForanea.sin_port ) << endl;

    return tam;
}

SocketDatagrama::~SocketDatagrama() {
    close( s );
}