#include "Solicitud.h"
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
//Varios clientes?
int main()
{
    int montoAleatorio = 0;
    string i; // = "127.0.0.1";
    cout << "Ingrese la IP: ";
    cin >> i;
    char *ip = new char[i.length()];
    strcpy(ip, i.c_str());
    Solicitud sol;
    int num[2], res, n;
    srand( time( nullptr ) );
    //cout << "Ingrese el numero de ciclos: ";
    cin >> n;
    montoAleatorio = ( rand() % 9 ) + 1;
    num[0] = n;
    for (int j = 0; j < n; j++){
        char *resServer = sol.doOperation(ip, 7200, 3, (char *)montoAleatorio);
        memcpy(&res, resServer, sizeof(res));
        cout << "Suma = " << res << endl;
    }
    return 0;
}