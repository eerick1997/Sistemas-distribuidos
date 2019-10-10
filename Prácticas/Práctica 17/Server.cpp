#include "Respuesta.h"
#include <iostream>
using namespace std;
int main()
{
    Respuesta server(7200);
    struct mensaje *request;
    unsigned int num[2], sum;
    int nbd = 0;
    while (1)
    {
        request = server.getRequest();
        memcpy(num, (*request).arguments, sizeof(num));
        nbd += num[0];
        //cout << num[0] << " + " << num[1] << " = " << sum << endl;
        //cout << nbd << endl;
        server.sendReply((char *)&nbd);
    }

    return 0;
}