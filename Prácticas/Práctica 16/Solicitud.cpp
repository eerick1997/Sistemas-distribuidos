#include "Solicitud.h"
#include <sys/time.h>

Solicitud::Solicitud()
{
    socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{
    short n = 7;
        time_t segundos = 2;
        suseconds_t microsegundos = 500000;

        struct mensaje datos;
        datos.messageType = 1123456;
        datos.requestId = 3343;
        datos.operationId = suma;
        memcpy(datos.arguments, arguments, sizeof(arguments));
        PaqueteDatagrama paq((char *)&datos, sizeof(datos), IP, puerto);
        
    int result = -1;
    while( (n--) > 0 && result < 0){
        result = socketlocal -> recibeTimeout( paq, segundos, microsegundos );
        socketlocal->envia(paq);
        if( result > 0 )
            break;
    }
    
    socketlocal->recibe(paq);
    memcpy(&response, paq.obtieneDatos(), paq.obtieneLongitud());
        

    
    return response.arguments;
}