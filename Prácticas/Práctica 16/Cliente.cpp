#include "Solicitud.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string i; // = "127.0.0.1";
    cout << "Ingrese la IP: ";
    cin >> i;
    char *ip = new char[i.length()];
    strcpy(ip, i.c_str());
    Solicitud sol;
    int num[2], res, n;
    cout << "Ingrese el numero de ciclos:";
    cin >> n;
    num[0] = 125;
    num[1] = 32;
    for (int j = 0; j < n; j++)
    {
        char *resServer = sol.doOperation(ip, 7200, 3, (char *)num);
        memcpy(&res, resServer, sizeof(res));
        cout << "Suma = " << res << endl;
    }
    return 0;
}