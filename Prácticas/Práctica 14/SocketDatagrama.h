#include "PaqueteDatagrama.h"
#include <sys/socket.h>
#include <bits/stdc++.h>
#include <netinet/in.h>

class SocketDatagrama{
    public:
        SocketDatagrama( int );
        ~SocketDatagrama();
        int recibe( PaqueteDatagrama &p );
        int envia( PaqueteDatagrama &p );
    
    private:
        struct sockaddr_in direccionLocal;
        struct sockaddr_in direccionForanea;
        int s;
};