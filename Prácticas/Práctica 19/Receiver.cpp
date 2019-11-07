#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <time.h>
#include <iostream>
#include <string.h>

using namespace std;

//Receptor
int main()
{
    const int portMulticast = 7200;
    const int TTL = 2;
    string IPM = "224.0.0.1";
    char *IP = (char *)IPM.c_str();
    int nbd = 0, status;
    PaqueteDatagrama datagramPacketMulticast(sizeof(int));
    SocketMulticast multicastSocket(portMulticast);
    multicastSocket.unirseGrupo(IP);
    while (1)
    {
        status = multicastSocket.recibeConfiable(datagramPacketMulticast);
        if (status > 0)
        {
            memcpy(&status, datagramPacketMulticast.obtieneDatos(), sizeof(status));
            nbd += status;
            cout << "Números monto actual: $ " << nbd << endl;
        }
        // cout << "Emitter IP address is: " << datagramPacketMulticast.obtieneDireccion() << endl;
    }
    multicastSocket.salirseGrupo(IP);
    return 0;
}