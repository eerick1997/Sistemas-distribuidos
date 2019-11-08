#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char const *argv[])
{
    PaqueteDatagrama paqueteDatos(34);
    int fileToWrite;
    if (argc != 3)
    {
        printf("Forma de uso: programa nombre_archivo PORT\n");
        exit(0);
    }

    if ((fileToWrite = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0666)) == -1)
    {
        perror(argv[1]);
        exit(-1);
    }

    // Inicializar socket con el puerto solicitado
    SocketDatagrama sock(atoi(argv[2]));

    // Recibir paquete de datos
    sock.recibe(paqueteDatos);

    // Copiar datos recibidos a buffer
    string data = paqueteDatos.obtieneDatos();

    // Escribir datos en archivo
    write(fileToWrite, data.c_str(), data.length());
    write(fileToWrite, "\n", strlen("\n"));

    write(1, data.c_str(), data.length());

    printf("\n");
    // Cerrar archivo
    close(fileToWrite);

    return 0;
}
