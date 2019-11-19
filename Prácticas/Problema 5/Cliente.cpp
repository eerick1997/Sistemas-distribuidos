#include "Solicitud.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <thread>

Solicitud solicitud1, solicitud2, solicitud3;

void termina03(char *mensaje, int id, char *IP, int PORT)
{
    timeval timestamp;
    char *response_server = solicitud1.doOperation(IP, PORT, id, mensaje);
    memcpy(&timestamp, response_server, sizeof(timestamp));
    if (timestamp.tv_sec == 0 && timestamp.tv_usec == 0)
    {
        cout << "Ya tienes registrado un voto previo" << endl;
    }
    else
    {
        cout << "Voto registrado" << endl;
    }
}

void termina46(char *mensaje, int id, char *IP, int PORT)
{
    timeval timestamp;
    char *response_server = solicitud2.doOperation(IP, PORT, id, mensaje);
    memcpy(&timestamp, response_server, sizeof(timestamp));
    if (timestamp.tv_sec == 0 && timestamp.tv_usec == 0)
    {
        cout << "Ya tienes registrado un voto previo" << endl;
    }
    else
    {
        cout << "Voto registrado" << endl;
    }
}

void termina79(char *mensaje, int id, char *IP, int PORT)
{
    timeval timestamp;
    char *response_server = solicitud3.doOperation(IP, PORT, id, mensaje);
    memcpy(&timestamp, response_server, sizeof(timestamp));
    if (timestamp.tv_sec == 0 && timestamp.tv_usec == 0)
    {
        cout << "Ya tienes registrado un voto previo" << endl;
    }
    else
    {
        cout << "Voto registrado" << endl;
    }
}

using namespace std;

int main(int32_t argc, char const *argv[])
{

    int32_t n = 0;
    Solicitud solicitud;
    int32_t file_to_read, response;
    char data[34];
    timeval timestamp;

    if (argc != 7)
    {
        cout << "Ingresar nombre del archivo, nombre archivo a leer, puerto, IP1, IP2, IP3, numero de registros " << endl;
        exit(-1);
    }
    if ((file_to_read = open(argv[1], O_RDONLY)) == -1)
        exit(-1);

    for (int32_t i = 0; i < atoi(argv[6]); i++)
    {
        read(file_to_read, data, 32);
        //write(1, data, 32);
        //write(1, "\n", 1);
        if (data[9] == '0' || data[9] == '1' || data[9] == '2' || data[9] == '3')
        {
            thread t1(termina03, data, i, (char *)argv[3], atoi(argv[2]));
        }
        else if (data[9] == '4' || data[9] == '5' || data[9] == '6')
        {
            thread t2(termina46, data, i, (char *)argv[4], atoi(argv[2]));
        }
        else if (data[9] == '7' || data[9] == '8' || data[9] == '9')
        {
            thread t2(termina79, data, i, (char *)argv[5], atoi(argv[2]));
        }
    }

    close(file_to_read);

    return 0;
}