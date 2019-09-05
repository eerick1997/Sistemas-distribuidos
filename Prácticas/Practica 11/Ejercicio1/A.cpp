#include <bits/stdc++.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

using namespace std;

char buffer[ 1 ];

string nueva_palabra(){
    string str = "";
    for( int i = 0; i < 3; i++ )
        str += ( ( rand() % 26 ) + ( 'A' ) );
    str += " ";
    return str;
}

int main(int argc, char *argv[]){
    int destino;
    string linea;

    srand( time( NULL ) );
    long long int n = 26 * 26 * 26 * 100;
    string cadenota = "";
    for( long long int i = 0; i < n; i++ )
        cadenota.append( nueva_palabra() );

    if(argc != 2){
        cout << "Forma de uso: " << argv[ 0 ] << "nombre_del_archivo\n";
        exit(0);
    }

    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if( (destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1 ){
        perror( argv[ 1 ] );
        exit( -1 );
    }
    
    for( int i = 0; i < cadenota.size(); i++ )
        write( destino, &cadenota[i], 1);
    
    fsync( destino );
    close( destino );
    return 0;
}