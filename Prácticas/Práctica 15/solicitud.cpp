#include <bits/stdc++.h>
#include "solicitud.h"
#include "mensaje.h"

using namespace std;


Solicitud::Solicitud(){
    socketlocal = new SocketDatagrama( 0 );
}

//Se envía al servidor
char *Solicitud::doOperation( char *IP, int puerto, int operationID, char *arguments ){
    int num[2], res;
    num[0] = 5;
    num[1] = 2;
    PaqueteDatagrama paq((char *)num, 2 * sizeof(int), IP, puerto);
    socketlocal -> envia( paq );
}
