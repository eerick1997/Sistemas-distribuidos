#include "Respuesta.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

using namespace std;

int main( int32_t argc, char const *argv[] ){

    PaqueteDatagrama paquete_datagrama( 34 * sizeof( char ) );
    struct mensaje *request;
    int32_t file_to_write;
    char data[ 34 ];
    if( argc != 3 ){
        cout << "Ingresar nombre archivo, archivo a leer, puerto" << endl;
        exit( -1 );
    }
    Respuesta respuesta( atoi( argv[ 2 ] ) );
    
    if ( ( file_to_write = open( argv[ 1 ], O_WRONLY | O_APPEND | O_CREAT, 0666 ) ) == -1)
        exit( -1 );
    
    while( true ){
        
        request = respuesta.getRequest();
        if( request != NULL ){
            memcpy( data, (char *)request -> arguments, 32 );
            write( file_to_write, data, 32 );
            //write( file_to_write, "\n", strlen("\n") );
            write( 1, data, 32 );
            respuesta.sendReply( (char *)&request -> requestId, suma );
            cout << endl;
        } else {
            respuesta.sendReply( (char *)&request -> requestId, REPETIDO );
        }
    }

    close( file_to_write );

    return 0;
}