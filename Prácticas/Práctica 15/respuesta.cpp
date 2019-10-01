#include <bits/stdc++.h>
#include "respuesta.h"
#include "mensaje.h"

using namespace std;

Respuesta::Respuesta( int P1 ){
    socketlocal = new SocketDatagrama( P1 );
}
//PaqueteDatagrama -> datos = el mensaje = 
struct mensaje *Respuesta::getRequest( void ){
    int num[2], res;
    struct mensaje *mensaje_cliente;
    int estado = 0;
    clientePaqueteDatagrama = new PaqueteDatagrama( 100 );
    estado = socketlocal -> recibe( *clientePaqueteDatagrama );
    printf("IP: %s\t|\tPORT: %d \n", clientePaqueteDatagrama -> obtieneDireccion(), clientePaqueteDatagrama -> obtienePuerto());
    memcpy( mensaje_cliente, clientePaqueteDatagrama -> obtieneDatos(), 8 );
    printf("Numeros: [ %d , %d ]\n", num[0], num[1]);
    return mensaje_cliente;
}

void Respuesta::sendReply( char *respuesta ){
    PaqueteDatagrama paqueteDatagrama( 100 );
    paqueteDatagrama.inicializaDatos( (char *) respuesta );
    paqueteDatagrama.inicializaIp( clientePaqueteDatagrama -> obtieneDireccion() );
    paqueteDatagrama.inicializaPuerto( clientePaqueteDatagrama -> obtienePuerto() );
    paqueteDatagrama.inicializaDatos( respuesta );
    socketlocal -> envia( paqueteDatagrama );
}


