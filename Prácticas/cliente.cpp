#include "SocketDatagrama.h"
#include <bits/stdc++.h>

using namespace std;

int puerto = 7200;
int MAXSIZE = 1000;

int main( void ){

    char *datos = new char[ MAXSIZE ];
    char *IP = "8.8.8.8";
    size_t SIZE = strlen( datos );
    SocketDatagrama socketDatagrama( puerto );
    getline( &datos, &SIZE, stdin );
    PaqueteDatagrama( datos, MAXSIZE, IP, puerto );

    return 0;
}