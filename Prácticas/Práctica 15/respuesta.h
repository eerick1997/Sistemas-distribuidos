#include "SocketDatagrama.h"
#ifndef RESPUESTA_H_
#define RESPUESTA_H_
class Respuesta{
    public:
        Respuesta( int p1 );
        struct mensaje *getRequest( void );
        void sendReply( char *respuesta );
    private:
        SocketDatagrama *socketlocal;
        PaqueteDatagrama *clientePaqueteDatagrama;
};
#endif 