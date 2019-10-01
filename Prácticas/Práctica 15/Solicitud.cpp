#include "Solicitud.h"
Solicitud::Solicitud()
{
    socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments)
{
    struct mensaje datos;
    datos.messageType = 1123456;
    datos.requestId = 3343;
    datos.operationId = suma;
    memcpy(datos.arguments, arguments, sizeof(arguments));
    PaqueteDatagrama paq((char *)&datos, sizeof(datos), IP, puerto);
    socketlocal->envia(paq);
    //PaqueteDatagrama paq2(sizeof(struct mensaje));
    socketlocal->recibe(paq);
    memcpy(&response, paq.obtieneDatos(), paq.obtieneLongitud());
    return response.arguments;
}