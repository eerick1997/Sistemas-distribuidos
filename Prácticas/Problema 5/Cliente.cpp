#include "Solicitud.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>
#include <thread>

using namespace std;
void termina03(char *nombre, int PORT, char *IP, int numRegistros)
{
    printf("%d\n", PORT);
    int32_t n = 0;
    Solicitud solicitud1;
    int32_t file_to_read1, response;
    char data[34];
    timeval timestamp;
    if ((file_to_read1 = open(nombre, O_RDONLY)) == -1)
        exit(-1);

    for (int32_t i = 0; i < numRegistros; i++)
    {
        read(file_to_read1, data, 32);
        if (data[9] == '0' || data[9] == '1' || data[9] == '2' || data[9] == '3')
        {
            char *response_server = solicitud1.doOperation(IP, PORT, i, data);
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
    }

    close(file_to_read1);
}

void termina46(char *nombre, int PORT, char *IP, int numRegistros)
{
    printf("%d\n", PORT);
    int32_t n = 0;
    Solicitud solicitud2;
    int32_t file_to_read2, response;
    char data[34];
    timeval timestamp;
    if ((file_to_read2 = open(nombre, O_RDONLY)) == -1)
        exit(-1);

    for (int32_t i = 0; i < numRegistros; i++)
    {
        read(file_to_read2, data, 32);
        if (data[9] == '4' || data[9] == '5' || data[9] == '6')
        {
            char *response_server = solicitud2.doOperation(IP, PORT, i, data);
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
    }

    close(file_to_read2);
}

void termina79(char *nombre, int PORT, char *IP, int numRegistros)
{
    int32_t n = 0;
    Solicitud solicitud3;
    int32_t file_to_read3, response;
    char data[34];
    timeval timestamp;
    if ((file_to_read3 = open(nombre, O_RDONLY)) == -1)
        exit(-1);

    for (int32_t i = 0; i < numRegistros; i++)
    {
        read(file_to_read3, data, 32);
        if (data[9] == '7' || data[9] == '8' || data[9] == '9')
        {
            char *response_server = solicitud3.doOperation(IP, PORT, i, data);
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
    }

    close(file_to_read3);
}

int main(int32_t argc, char const *argv[])
{

    if (argc != 9)
    {
        cout << "Ingresar nombre del archivo, nombre archivo a leer, puerto1, puerto2, puerto3, IP1, IP2, IP3, numero de registros " << endl;
        exit(-1);
    }

    thread term03(termina03, (char *)argv[1], atoi(argv[2]), (char *)argv[5], atoi(argv[8]));
    thread term46(termina46, (char *)argv[1], atoi(argv[3]), (char *)argv[6], atoi(argv[8]));
    thread term79(termina79, (char *)argv[1], atoi(argv[4]), (char *)argv[7], atoi(argv[8]));
    term03.join();
    term46.join();
    term79.join();

    return 0;
}