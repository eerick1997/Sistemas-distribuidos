#include <bits/stdc++.h>
#include "SocketMuilticast.h"
#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <time.h>

using namespace std;

//Receptor
int main()
{
    SocketMulticast socketMulticast( 7200 );
    SocketDatagrama socketDatagrama( 8080 );
    int result = 0;
    string i;
    cout << "Ingrese la IP: ";
    //224.0.0.1
    cout << "IP group: ";
    cin >> i;
    cout << endl;
    char *ip = new char[i.length()];
    strcpy(ip, i.c_str());
    int num[2];
    srand(time(nullptr));
    PaqueteDatagrama paqueteServer( sizeof( num ) );
    socketMulticast.unirseGrupo( ip );        
    socketMulticast.recibe( paqueteServer );
    memcpy(num, paqueteServer.obtieneDatos(), sizeof(num));
    cout << num[ 0 ] << " | " << num[ 1 ] << endl;         
    cout << num[ 0 ] + num[ 1 ] << endl;
    result = num[ 0 ] + num[ 1 ];
    PaqueteDatagrama paquete(  (char*)&result, sizeof( int ), paqueteServer.obtieneDireccion(), 7200 );
    socketDatagrama.envia( paquete );
    return 0;
}