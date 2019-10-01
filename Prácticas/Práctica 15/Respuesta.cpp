#include "Respuesta.h"
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
    return &petition;
}

void Respuesta::sendReply(char *respuesta)
{
    mensaje response = {.messageType = 0, .requestId = 3, .operationId = suma};
    memcpy(response.arguments, respuesta, sizeof(respuesta));
    PaqueteDatagrama paqueteDatagrama(sizeof(struct mensaje));
    paqueteDatagrama.inicializaDatos((char *)&response);
    paqueteDatagrama.inicializaIp(clientePaqueteDatagrama->obtieneDireccion());
    paqueteDatagrama.inicializaPuerto(clientePaqueteDatagrama->obtienePuerto());
    socketlocal->envia(paqueteDatagrama);
}
