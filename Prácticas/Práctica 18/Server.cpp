#include "SocketMuilticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <thread>

using namespace std;

const int portMulticast = 7200;
const int portDatagram = 8080;
const int TTL = 1;
char *IP = "224.0.0.1";

//Emisor

void UDPUnicast()
{
    int result;
    SocketDatagrama socketDatagrama(portDatagram);
    PaqueteDatagrama datagramPacketResult(sizeof(int));
    while (1)
    {
        cout << socketDatagrama.recibe(datagramPacketResult) << endl;
        memcpy(&result, datagramPacketResult.obtieneDatos(), sizeof(result));
        cout << "The sum is: " << result << endl;
        fflush(stdout);
    }
}

int main()
{
    int numbers[2] = {4, 5};
    SocketMulticast socketMulticast(portMulticast);
    thread th1(UDPUnicast);
    PaqueteDatagrama datagramPacketMulticast((char *)numbers, sizeof(numbers), IP, portMulticast);
    while (1)
    {
        socketMulticast.envia(datagramPacketMulticast, TTL);
    }
    return 0;
}
