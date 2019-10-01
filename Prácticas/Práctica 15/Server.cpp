#include "SocketDatagrama.h"
#include "respuesta.h"
#include <bits/stdc++.h>
int main()
{
    //SocketDatagrama sock(7200);
    //PaqueteDatagrama paq(8), paq2(4);
    Respuesta respuesta( 0 );
    int num[2], res;
    while ( true ){
        struct mensaje *Mensaje = NULL;
        Mensaje = respuesta.getRequest();
        res = Mensaje -> arguments = 
        respuesta.sendReply()
        /*sock.recibe(paq);
        printf("IP: %s\t|\tPORT: %d \n", paq.obtieneDireccion(), paq.obtienePuerto());
        memcpy(num, paq.obtieneDatos(), 8);
        printf("Numeros: [ %d , %d ]\n", num[0], num[1]);
        res = num[0] + num[1];
        paq2.inicializaDatos((char *)&res);
        paq2.inicializaIp(paq.obtieneDireccion());
        paq2.inicializaPuerto(paq.obtienePuerto());
        sock.envia(paq2);*/
    }
    return 1;
}