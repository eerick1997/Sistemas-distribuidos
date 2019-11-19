#include "Solicitud.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/time.h>

using namespace std;

int main(int32_t argc, char const *argv[])
{

    int32_t n = 0;
    Solicitud solicitud;
    int32_t file_to_read, response;
    char data[34];
    timeval timestamp;

    if (argc != 5)
    {
        cout << "Ingresar nombre del archivo, nombre archivo a leer, puerto, IP, numero de registros " << endl;
        exit(-1);
    }
    if ((file_to_read = open(argv[1], O_RDONLY)) == -1)
        exit(-1);

    do
    {
        lseek(file_to_read, 0L, SEEK_SET);
        for (int32_t i = 0; i < atoi(argv[4]); i++)
        {
            read(file_to_read, data, 32);
            //write(1, data, 32);
            //write(1, "\n", 1);
            char *response_server = solicitud.doOperation((char *)argv[3], atoi(argv[2]), i, data);
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
        n++;
    } while (n < 2);

    close(file_to_read);

    return 0;
}