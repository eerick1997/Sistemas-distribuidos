#include "Solicitud.h"
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
//Varios clientes?
int main()
{
    int montoAleatorio = 0, nbd = 0;
    string i; // = "127.0.0.1";
    cout << "Ingrese la IP: ";
    cin >> i;
    char *ip = new char[i.length()];
    strcpy(ip, i.c_str());
    Solicitud sol;
    int num[2], res, n;
    srand(time(nullptr));
    //cout << "Ingrese el numero de ciclos: ";
    cin >> n;
    num[0] = n;
    for (int j = 0; j < n; j++)
    {
        montoAleatorio = (rand() % 9) + 1;
        cout << montoAleatorio << endl;
        char *resServer = sol.doOperation(ip, 7200, 3, (char *)&montoAleatorio);
        memcpy(&res, resServer, sizeof(res));
        nbd += montoAleatorio;
        cout << nbd << "||" << res << endl;
        //printf("%d | %d\n", nbd, res);
        if (nbd != res)
        {
            cout << "No coinciden las cantidades, sevidor me devolvió: " << res << " yo tengo registrado " << nbd << endl;
            exit(0);
        }
        //cout << "Servidor dice que tengo = " << res << " pesos" << endl;
    }
    return 0;
}