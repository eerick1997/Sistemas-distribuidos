#include "Respuesta.h"
#include <iostream>
using namespace std;
int main()
{
    Respuesta server(7200);
    struct mensaje *request;
    unsigned int num[2], sum;
    while (1)
    {
        request = server.getRequest();
        memcpy(num, (*request).arguments, sizeof(num));
        sum = num[0] + num[1];
        cout << num[0] << " + " << num[1] << " = " << sum << endl;
        server.sendReply((char *)&sum);
    }

    return 0;
}