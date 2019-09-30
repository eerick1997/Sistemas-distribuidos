#include "SocketDatagrama.h"

#ifndef SOLICITUD_H_
#define SOLICITUD_H_
class Solicitud{
    public:
        Solicitud();
        char *doOperation( char *IP, int puerto, int operationID, char *arguments );
    private:
        SocketDatagrama *socketlocal;
};
#endif SOLICITUD_H_