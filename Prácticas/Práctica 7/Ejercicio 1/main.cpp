#include "Poligono.h"

using namespace std;

double frand( ){
    double f = (double)( rand()  / (double)RAND_MAX );
    double i = rand() % 100;
    double r = f + i;
    r *= ( rand() % 1 == 0 ) ? -1 : 1;
    return r;
}

int main(){
    Poligono p;
    int n;
    srand( time( NULL ) );
    cin >> n;
    while( n-- ){
        p.anadieVertice( Coordenada( frand( ), frand( ) ) );
    }
    p.imprimeVertices();
    
}