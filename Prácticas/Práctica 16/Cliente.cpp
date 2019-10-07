#include "Solicitud.h"
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string i = "127.0.0.1";
    char *ip = new char[i.length()];
    strcpy(ip, i.c_str());
    Solicitud sol;
    int num[2], res;
    num[0] = 125;
    num[1] = 32;
    char *resServer = sol.doOperation(ip, 7200, 3, (char *)num);
    memcpy(&res, resServer, sizeof(res));
    cout << "Suma = " << res << endl;
    return 0;
}