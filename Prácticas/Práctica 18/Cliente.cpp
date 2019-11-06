#include "SocketMulticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <time.h>
#include <iostream>
#include <string.h>

using namespace std;

const int portMulticast = 7200;
const int portDatagram = 8080;
const int TTL = 2;
string IPM = "224.0.0.1";
char *IP = (char *)IPM.c_str();

//Receptor
int main()
{
    int numbers[2], result[1];
    PaqueteDatagrama datagramPacketMulticast(sizeof(int) * 4);
    SocketMulticast multicastSocket(portMulticast);
    SocketDatagrama datagramSocket(portDatagram);
    multicastSocket.unirseGrupo(IP);
    multicastSocket.recibe(datagramPacketMulticast);
    memcpy(numbers, datagramPacketMulticast.obtieneDatos(), sizeof(numbers));
    cout << "Números recibidos: [ " << numbers[0] << " , " << numbers[1] << " ]" << endl;
    result[0] = numbers[0] + numbers[1];
    cout << "Emitter IP address is: " << datagramPacketMulticast.obtieneDireccion() << endl;
    PaqueteDatagrama datagramPacketSend((char *)result, sizeof(result), datagramPacketMulticast.obtieneDireccion(), portDatagram);
    datagramSocket.envia(datagramPacketSend);
    multicastSocket.salirseGrupo(IP);
    return 0;
}