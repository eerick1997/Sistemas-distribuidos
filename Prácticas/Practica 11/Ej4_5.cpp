#include <bits/stdc++.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <thread>

using namespace std;

char buffer[ 1 ];

#define numeroElementos 100000000
void RAM(){
    int *arreglo, i;
    arreglo = new int[numeroElementos];
    for(i = 0; i < numeroElementos; i++)
        arreglo[i] = 0;
    for(i = 0; i < 100000000; i++){
        arreglo[rand()%numeroElementos] = rand();
    }
}

string nueva_palabra(){
    string str = "";
    for( int i = 0; i < 3; i++ )
        str += ( ( rand() % 26 ) + ( 'A' ) );
    str += " ";
    return str;
}

void hilo1( string nombre ){
int destino;
    string linea;

    srand( time( NULL ) );
    long long int n = 26 * 26 * 26 * 100;
    string cadenota = "";
    for( long long int i = 0; i < n; i++ )
        cadenota.append( nueva_palabra() );

    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if( (destino = open(nombre.c_str(), O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1 ){
        perror( nombre.c_str() );
        exit( -1 );
    }
    
    for( int i = 0; i < cadenota.size(); i++ )
        write( destino, &cadenota[i], 1);
    
    fsync( destino );
    close( destino );
}

void CPU(){
    double i = 0;
	int Max = 10000000;
	double seno, coseno, tangente, logaritmo, raizCuad;
	while (i < Max){
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log (i);
		raizCuad += sqrt(i);
		i++;
	}
}

int main(int argc, char *argv[]){

    thread thread1( hilo1, argv[1] ), thread2( RAM );
    thread1.join();
    thread2.join();
    return 0;
}