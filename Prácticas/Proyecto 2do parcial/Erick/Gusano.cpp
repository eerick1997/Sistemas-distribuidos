#include "Gusano.h"
#include <bits/stdc++.h>

using namespace std;

mt19937_64 semilla(chrono::steady_clock::now().time_since_epoch().count());

const int CIRCULO = 0;
const int CURVA = 1;
const int mov[ 3 ] = {1, -1, 0}, mult[ 2 ] = {1, -1}; 

Gusano::Gusano ( int tamanio, int modulo_x, int modulo_y ) : tamanio(tamanio), modulo_x(modulo_x), modulo_y(modulo_y) {  
    srand( time( nullptr ) );

    multiplicador = uniform_int_distribution< int >(1, 10)( semilla );

    int x = mult[ uniform_int_distribution< int >(0, 1)( semilla ) ];
    int y = mult[ uniform_int_distribution< int >(0, 1)( semilla ) ];
    
    Coordenada coordenada( x, y );

    x = uniform_int_distribution< int >(0, modulo_x)( semilla );
    y = uniform_int_distribution< int >(0, modulo_y)( semilla );

    Coordenada inicio( x, y );
    gusano.resize( multiplicador * tamanio );
    gusano[ 0 ] = inicio;
    for( int i = 1; i < (multiplicador * tamanio); i++ ){
        x = int( gusano[ i - 1 ].obtenerX() + coordenada.obtenerX() ) % modulo_x;
        y = int( gusano[ i - 1 ].obtenerY() + coordenada.obtenerY() ) % modulo_y;
        if( x < 0 )
            x += modulo_x;
        if( y < 0 )
            y += modulo_y;
        gusano[ i ] = Coordenada( x, y );
    }
    offset = 0;
}

int Gusano::obtenerTamanio(){
    return tamanio;
}

int Gusano::obtenerCentroX( int radio, int posicionicion ){
    int centro_x = int( gusano[ gusano.size() - 1 ].obtenerX() + ( posicionicion * radio ) ) % modulo_x;
    if( centro_x < 0 )
        centro_x += modulo_x;
    return centro_x;
}

int Gusano::obtenerCentroY(  ){
    int centro_y = int( gusano[ gusano.size() - 1 ].obtenerY() ) % modulo_y; 
    if( centro_y < 0 )
        centro_y += modulo_y;
    return centro_y;
}

vector< Coordenada > Gusano::obtenerCurva( int radio, int centro_x, int centro_y, int posicion, bool arriba ){
    vector< Coordenada > curva;
    int radio_2 = radio * radio, x, y, x_1, y_1;

    for( x = -radio; x <= radio; x++ ){
        x_1 = ( centro_x + x ) % modulo_x;
        y = (int)( sqrt( radio_2 - x * x ) + 0.5 );
        if( arriba )
            y_1 = ( centro_y - y ) % modulo_y;
        else 
            y_1 = ( centro_y + y ) % modulo_y;
        if( x_1 < 0 ) 
            x_1 += modulo_x;
        if( y_1 < 0 ) 
            y_1 += modulo_y;
        curva.push_back(Coordenada(x_1,y_1));
    }

    if(posicion == -1)
        reverse( begin( curva ), end( curva ) );

    return curva;
}

vector< Coordenada > Gusano::mover() {
    vector<Coordenada> aux;
    int movimiento, radio, posicion, centro_x, centro_y, arriba, curvas;
    int escalar = 1;
    if( (offset + tamanio) == gusano.size() ){
		
		for(int i = offset; i < gusano.size(); i++)
			aux.push_back( gusano[i] );
		
		gusano.clear();
		for( Coordenada coordenada : aux ) 
			gusano.push_back( coordenada );
		
        aux.clear();

		movimiento = uniform_int_distribution<int>(0, 2)( semilla );
		posicion = mult[uniform_int_distribution<int>(0,1)( semilla )];
        arriba = uniform_int_distribution<int>(0,1)( semilla );

		if( movimiento == CIRCULO ){
			
			radio = uniform_int_distribution<int>(10,250)( semilla );
			
			centro_x = obtenerCentroX( radio, posicion );
			centro_y = obtenerCentroY();

			aux = obtenerCurva( radio, centro_x, centro_y, posicion, arriba );
			
			for( Coordenada coordenada : aux ) 
				gusano.push_back( coordenada );

		} else if(movimiento == CURVA){
			
			curvas = uniform_int_distribution<int>(1,5)( semilla );
			radio = uniform_int_distribution<int>(10,150)( semilla );f
			
			for(int i = 0; i < curvas; i++){

				int centro_x = obtenerCentroX( radio, posicion );
			    int centro_y = obtenerCentroY(); 
				
				aux = obtenerCurva( radio, centro_x, centro_y, posicion, arriba );
				
				for( Coordenada coordenada : aux ) 
				    gusano.push_back( coordenada );
				
				arriba = !arriba;
			}
			
		} else {
		
			Coordenada vec( double( escalar * mov[ rand() % 3 ] ), double( escalar * mov[ rand() % 3 ] ) );
			int u_i = gusano.size()-1;
			for(int i =0; i < tamanio; i++, u_i++){
				int x = int( gusano[ u_i ].obtenerX() + vec.obtenerX() ) % modulo_x;
				if( x < 0 ) 
                 x += modulo_x;
				int y = int( gusano[ u_i ].obtenerY() + vec.obtenerY() )% modulo_y;
				if( y < 0 ) 
                    y += modulo_y;
				gusano.push_back( Coordenada( double( x ), double( y ) ) );
			}
		}
		offset = 0;
	}
    aux.clear();
	for( int i = offset; i < offset + tamanio; i++ )
		aux.push_back(gusano[i]);
	offset++;
	return aux;
}