#include <bits/stdc++.h>
#include <unistd.h>
#include "Gusano.h"
#include "gfx.h"

using namespace std;

int main(){
    int n_gusanos = 0, longitud = 0;
    unsigned int ancho = 1920;
    unsigned int largo = 1080;
    srand( time(nullptr) );
    random_device device;
    mt19937 generator( device() );
    uniform_int_distribution<> distribution_ancho(0, ancho);
    uniform_int_distribution<> distribution_largo(0, largo);
    uniform_int_distribution<> distribution_posicion(0, 2);

    vector< Gusano > gusanos;
    cin >> n_gusanos >> longitud; 
    
    for( int i = 0; i < n_gusanos; i++){
        double x = distribution_ancho( generator );
        double y = distribution_largo( generator );
        int mover_a = distribution_posicion( generator );
        gusanos.push_back( Gusano( longitud, x, y, mover_a ) );
    }
    gfx_open( largo, ancho, "Ejemplo microanimación gusanos");
    gfx_color( 0, 200, 100 );
    while( true ){
        gfx_clear();
        for( int j = 0; j < n_gusanos; j++ ){
            (gusanos[ j ].mover());
            for( int i = 0; i < longitud - 1; i++ )
                gfx_line( gusanos[ j ].obtenerGusano()[ i ].obtenerX(),
                gusanos[ j ].obtenerGusano()[ i ].obtenerY(),
                gusanos[ j ].obtenerGusano()[ i + 1 ].obtenerX(),
                gusanos[ j ].obtenerGusano()[ i + 1 ].obtenerY() );
        }
        gfx_flush();
        usleep( 41666 );
    }
    return 0;
}