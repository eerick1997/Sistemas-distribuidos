#include "SocketMuilticast.h"
#include <iostream>
using namespace std;
int main()
{
    SocketMulticast sm( 0 );
    struct mensaje *request;
    int num[ 2 ];
    string IP;
    int nbd = 0;
    cin >> IP;
    while (1) {
        cin >> num[ 0 ] >> num [ 1 ];
        char *ip = new char[ IP.size() ];
        strcpy( ip, IP.c_str() );
        cout << ip << endl;
        PaqueteDatagrama p( (char *)num, sizeof( num ), ip, 7200 );
        sm.envia( p, 2 );
    }
    return 0;
}