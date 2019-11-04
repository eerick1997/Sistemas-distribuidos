#include "SocketMuilticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>

using namespace std;

//Emisor
int main(){
    SocketMulticast sm( 0 );
    SocketDatagrama socketDatagrama( 8080 );
    struct mensaje *request;
    int num[ 2 ];
    int result = 0;
    string IP;
    int nbd = 0;
    cout << "Type IP: ";
    cin >> IP;
    cout << endl;
    while ( true ) {
        cout << "Type two numbers: ";
        cin >> num[ 0 ] >> num [ 1 ];
        cout << endl;
        char *ip = new char[ IP.size() ];
        strcpy( ip, IP.c_str() );
        cout << ip << endl;
        PaqueteDatagrama p( (char *)num, sizeof( num ), ip, 7200 );
        PaqueteDatagrama p2( sizeof( int ) );
        sm.envia( p, 2 );
        socketDatagrama.recibe( p2 );
        memcpy( &result, p2.obtieneDatos(), sizeof( int ) );
        cout << "result = " << result << endl;
    }
    return 0;
}
