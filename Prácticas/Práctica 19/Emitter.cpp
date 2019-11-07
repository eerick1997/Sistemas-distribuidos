#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

int main()
{
    const int portMulticast = 7200;
    const int TTL = 1;
    string IPM = "224.0.0.1";
    char *IP = (char *)IPM.c_str();
    int montoAleatorio = 0, nbd = 0, n, status, nReceivers;
    srand(time(nullptr));
    cout << "Ingrese el numero de receptores: ";
    cin >> nReceivers;
    cout << "Ingrese el numero de depositos: ";
    cin >> n;
    SocketMulticast socketMulticast(portMulticast);
    PaqueteDatagrama datagramPacketMulticast((char *)&montoAleatorio, sizeof(montoAleatorio), IP, portMulticast);
    for (int i = 0; i < n; i++)
    {
        montoAleatorio = (rand() % 9) + 1;
        datagramPacketMulticast.inicializaDatos((char *)&montoAleatorio);
        do
        {
            status = socketMulticast.enviaConfiable(datagramPacketMulticast, TTL, nReceivers);

        } while (status < 0);
        nbd += montoAleatorio;
        cout << "Monto actual: $ " << nbd << endl;
    }
    return 0;
}
