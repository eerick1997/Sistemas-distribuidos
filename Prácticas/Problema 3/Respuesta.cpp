#include "Respuesta.h"

int Respuesta::requestIDR = 0;
Respuesta::Respuesta(int port)
{
    socketlocal = new SocketDatagrama(port);
    clientePaqueteDatagrama = new PaqueteDatagrama(sizeof(mensaje));
    requestIDO = 0;
}

struct mensaje *Respuesta::getRequest(void)
{
    PaqueteDatagrama paq(sizeof(struct mensaje));
    socketlocal->recibe(paq);
    memcpy(clientePaqueteDatagrama, &paq, sizeof(paq));
    memcpy(&petition, clientePaqueteDatagrama->obtieneDatos(), clientePaqueteDatagrama->obtieneLongitud());
    if (petition.requestId == requestIDR)
        requestIDO = petition.requestId, requestIDR++;
    else
    {
        printf("Mensaje repetido\n");
        return NULL;
    }
    return &petition;
}

void Respuesta::sendReply(char *respuesta, int type)
{
    mensaje response = {.messageType = type, .requestId = (unsigned int)requestIDO, .operationId = suma};
    memcpy(response.arguments, respuesta, TAM_MAX_DATA);
    PaqueteDatagrama paqueteDatagrama(sizeof(struct mensaje));
    paqueteDatagrama.inicializaDatos((char *)&response);
    paqueteDatagrama.inicializaIp(clientePaqueteDatagrama->obtieneDireccion());
    paqueteDatagrama.inicializaPuerto(clientePaqueteDatagrama->obtienePuerto());
    socketlocal->envia(paqueteDatagrama);
}
