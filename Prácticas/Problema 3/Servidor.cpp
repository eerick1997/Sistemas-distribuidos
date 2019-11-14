#include "Respuesta.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <string.h>
#include <algorithm>

using namespace std;


set< string > CURP;

int main(int32_t argc, char const *argv[])
{

    PaqueteDatagrama paquete_datagrama(34 * sizeof(char));
    struct mensaje *request;
    int32_t file_to_write;
    char data[34], timestamp[40];
    timeval tiempo;
    if (argc != 3)
    {
        cout << "Ingresar nombre archivo, archivo a leer, puerto" << endl;
        exit(-1);
    }
    Respuesta respuesta(atoi(argv[2]));

    if ((file_to_write = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0666)) == -1)
        exit(-1);

    while (true)
    {

        request = respuesta.getRequest();
        if (request != NULL)
        {
            memcpy(data, (char *)request->arguments, 31);
            if( CURP.count( data ) == 0 ) {
                CURP.insert( data );
                write(file_to_write, data, 31);
                gettimeofday(&tiempo, NULL);
                int n = sprintf(timestamp, "%ld%ld", tiempo.tv_sec, tiempo.tv_usec);
                write(file_to_write, timestamp, n);
                write(file_to_write, "\n", strlen("\n"));
                fsync(file_to_write);
                write(1, data, 31);
                write(1, timestamp, n);
                write(1, "\n", strlen("\n"));
                respuesta.sendReply((char *)&request->requestId, suma);
            } else {
                tiempo.tv_sec = 0; 
                tiempo.tv_usec = 0;
                respuesta.sendReply( (char *)&tiempo, REPETIDO );
            }
            //cout << endl;
        }
        else
        {
            respuesta.sendReply((char *)&request->requestId, REPETIDO);
        }
    }

    close(file_to_write);

    return 0;
}