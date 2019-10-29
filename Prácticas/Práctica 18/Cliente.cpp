#include <bits/stdc++.h>
#include "SocketMuilticast.h"
#include <time.h>
using namespace std;
//Varios clientes?
int main()
{
    SocketMulticast socketMulticast( 7200 );
    
    int montoAleatorio = 0, nbd = 0;
    string i;
    cout << "Ingrese la IP: ";
    cin >> i;
    char *ip = new char[i.length()];
    strcpy(ip, i.c_str());
    int num[2];
    srand(time(nullptr));
    PaqueteDatagrama paquete(  (char*)&num, sizeof( num ), ip, 7200 );
    PaqueteDatagrama paqueteServer( sizeof( num ) );
    socketMulticast.unirseGrupo( ip );        
    socketMulticast.recibe( paqueteServer );
    memcpy(num, paqueteServer.obtieneDatos(), sizeof(num));
    cout << num[ 0 ] << num[ 1 ];         
    return 0;
}