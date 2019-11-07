#include <bits/stdc++.h>
#include <unistd.h>
#include "Gusano.h"
#include "gfx.h"

using namespace std;

mt19937_64 semilla_main(chrono::steady_clock::now().time_since_epoch().count());

int main(){
    int n_gusanos = 0, longitud = 0, x, y;
    unsigned int ancho = 1920;
    unsigned int largo = 1080;
    srand( time(nullptr) );
    
    cin >> n_gusanos >> longitud; 
    vector< Gusano* > gusanos( n_gusanos );
    for( int i = 0; i < n_gusanos; i++ )
        gusanos[ i ] = new Gusano( longitud, ancho, largo );
    
    gfx_open( ancho, largo, "Gusanos" );

    while( true ){
        for( Gusano* gusano : gusanos ){
            vector< Coordenada > pintar = gusano -> mover();
            for( Coordenada coordenada : pintar ){
                gfx_color( 0, 200, 100 );
                x = coordenada.obtenerX();
                y = coordenada.obtenerY();
                if( x < 0 )
                    x += ancho;
                if( y < 0 )
                    y += largo;
                gfx_point( x, y );
            }
        }
        gfx_flush();
        gfx_clear();
        usleep( 1000 );
    }

    return 0;
}