#include "SocketDatagrama.h"
#include "PaqueteDatagrama.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
using namespace std;

int main(int argc, char const *argv[])
{
    char datos[34];
    PaqueteDatagrama paqueteDatos(sizeof datos);
    SocketDatagrama sock(0);
    int fileToRead;
    if (argc != 4)
    {
        printf("Forma de uso: programa nombre_archivo IP PORT\n");
        exit(0);
    }

    if ((fileToRead = open(argv[1], O_RDONLY)) == -1)
    {
        perror(argv[1]);
        exit(-1);
    }

    // Leer datos de archivo
    read(fileToRead, datos, sizeof datos);

    // Inicilizar paquete a enviar
    paqueteDatos.inicializaIp((char *)argv[2]);
    paqueteDatos.inicializaPuerto(atoi(argv[3]));
    paqueteDatos.inicializaDatos(datos);

    // Enviar paquete
    sock.envia(paqueteDatos);

    // Cerrar archivo
    close(fileToRead);

    return 0;
}
