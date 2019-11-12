#include "Solicitud.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

using namespace std;

int main( int32_t argc, char const *argv[] ){

    int32_t n;
    Solicitud solicitud;
    int32_t file_to_read, response;
    char data[ 34 ];

    if( argc != 5 ){
        cout << "Ingresar nombre del archivo, nombre archivo a leer, puerto, IP, numero de registros " << endl;
        exit( -1 );
    }
    if (( file_to_read = open( argv[ 1 ], O_RDONLY)) == -1 )
        exit( -1 );
    
    for( int32_t i = 0; i < atoi( argv[ 4 ] ); i++ ){
        read( file_to_read, data, 32 );
        //write(1, data, 32);
        //write(1, "\n", 1);
        char *response_server = solicitud.doOperation( (char *)argv[ 3 ], atoi( argv[ 2 ] ), i, data );
        memcpy( &response, response_server, sizeof( response ) );
        printf("%d\n", response);
    }

    close( file_to_read );

    return 0;
}