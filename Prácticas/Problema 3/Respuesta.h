#include "Mensaje.h"
#include "SocketDatagrama.h"
class Respuesta
{
public:
    Respuesta(int port);
    struct mensaje *getRequest(void);
    void sendReply(char *respuesta, int type);

private:
    SocketDatagrama *socketlocal;
    PaqueteDatagrama *clientePaqueteDatagrama;
    struct mensaje petition;
    static int requestIDR;
    int requestIDO;
};