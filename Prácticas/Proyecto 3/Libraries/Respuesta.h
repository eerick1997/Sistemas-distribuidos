#include "Mensaje.h"
#include <string>
#include "SocketDatagrama.h"
class Respuesta{
public:
    Respuesta(int port);
    struct mensaje *getRequest(void);
    char *obtenerDireccion(void);
    void sendReply(char *respuesta, int type);

private:
    SocketDatagrama *socketlocal;
    PaqueteDatagrama *clientePaqueteDatagrama;
    struct mensaje petition;
    static int requestIDR;
    int requestIDO;
};