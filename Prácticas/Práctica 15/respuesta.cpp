#include <bits/stdc++.h>
#include "respuesta.h"
#include "mensaje.h"

using namespace std;

Respuesta::Respuesta( int P1 ){
    socketlocal = new SocketDatagrama( P1 );
}

/*
*   Server -> mensaje -> respuesta
*/
struct mensaje *Respuesta::getRequest( void ){
    struct mensaje *Mensaje;
    PaqueteDatagrama p1( 0 );
    socketlocal -> recibe( p1 );
    PaqueteDatagrama paq((char *)num, 2 * sizeof(int), ip, 7200);
    return Mensaje;
}

void Respuesta::sendReply( char *respuesta ){
    PaqueteDatagrama p1( 0 );
    socketlocal -> envia( p1 );
}


