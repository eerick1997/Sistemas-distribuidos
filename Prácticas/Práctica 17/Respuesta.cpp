#include "Respuesta.h"

int Respuesta::requestIDR = 0;
Respuesta::Respuesta(int port)
{
    socketlocal = new SocketDatagrama(port);
    clientePaqueteDatagrama = new PaqueteDatagrama(sizeof(mensaje));
}

struct mensaje *Respuesta::getRequest(void)
{
    PaqueteDatagrama paq(sizeof(struct mensaje));
    socketlocal->recibe(paq);
    memcpy(clientePaqueteDatagrama, &paq, sizeof(paq));
    memcpy(&petition, clientePaqueteDatagrama->obtieneDatos(), clientePaqueteDatagrama->obtieneLongitud());
    printf("%d | %d \n", petition.requestId, requestIDO);
    if( petition.requestId != requestIDO )
        requestIDO = petition.requestId;
    else {
        printf("Mensaje repetido\n");
        return NULL;
    }
    return &petition;
}

void Respuesta::sendReply(char *respuesta, int type)
{
    //if (requestIDO == requestIDR)
    //{
        mensaje response = {.messageType = type, .requestId = requestIDO, .operationId = suma};
        memcpy(response.arguments, respuesta, sizeof(respuesta));
        PaqueteDatagrama paqueteDatagrama(sizeof(struct mensaje));
        paqueteDatagrama.inicializaDatos((char *)&response);
        paqueteDatagrama.inicializaIp(clientePaqueteDatagrama->obtieneDireccion());
        paqueteDatagrama.inicializaPuerto(clientePaqueteDatagrama->obtienePuerto());
        socketlocal->envia(paqueteDatagrama);
        requestIDR++;
    //}
}
