#include "SocketDatagrama.h"
#include <string>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    SocketDatagrama sock(6666);
    int num[2], res;
    // string m = "Hola";
    // string i = "127.0.0.1";
    // char *msg = new char[m.length()];
    // char *ip = new char[i.length()];
    // strcpy(msg, m.c_str());
    // strcpy(ip, i.c_str());
    // PaqueteDatagrama paq(msg, m.length() + 1, ip, 7200);
    // sock.envia(paq);
    string i = "10.100.66.155";
    char *ip = new char[i.length()];
    strcpy(ip, i.c_str());
    num[0] = 5;
    num[1] = 2;
    PaqueteDatagrama paq((char *)num, 2 * sizeof(int), ip, 7200);
    sock.envia(paq);

    sock.recibe(paq);
    printf("IP: %s\t|\tPORT: %d \n", paq.obtieneDireccion(), paq.obtienePuerto());
    memcpy(&res, paq.obtieneDatos(), 4);
    printf("Respuesta: %d\n", res);
    return 1;
}