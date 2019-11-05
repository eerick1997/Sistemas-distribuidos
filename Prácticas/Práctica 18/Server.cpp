#include "SocketMuilticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>

using namespace std;

const int portMulticast = 7200;
const int portDatagram = 8080;
const int TTL = 1;
char* IP = "224.0.0.1";
//Emisor
int main() {
    int numbers[ 2 ] = {4, 5};
    SocketMulticast socketMulticast( portMulticast );
    PaqueteDatagrama datagramPacketMulticast( (char *)numbers, sizeof( numbers ), IP, portMulticast  );
    SocketDatagrama socketDatagrama( portDatagram );
    PaqueteDatagrama datagramPacketDatagram( sizeof( int ) ), 
    datagramPacketResult( sizeof( int ) );
    while( socketMulticast.envia( datagramPacketMulticast, TTL ) > 0 ) {
        int result[ 1 ];
        cout << socketDatagrama.recibe( datagramPacketResult ) << endl;
        memcpy( result, datagramPacketResult.obtieneDatos(), sizeof( result ) );
        cout << "The sum is: " << result[ 0 ] << endl;
    }
    return 0;
}
