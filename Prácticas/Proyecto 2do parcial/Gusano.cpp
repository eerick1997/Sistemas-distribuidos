#include "Gusano.h"
#include <bits/stdc++.h>

using namespace std;

Gusano::Gusano( int tamanio, double x, double y, int mover_a ){
    //cout << "Gusano" << endl;
    this -> tamanio = tamanio;
    //Mover hacía abajo
    if( mover_a == 0 )
        for( int i = 0; i < tamanio; i++ )
            gusano.push_back( Coordenada( x + i, y ) );
    else if( mover_a == 1 )
        for( int i = 0; i < tamanio; i++ )
            gusano.push_back( Coordenada( x, y + i) );
    else 
        for( int i = 0; i < tamanio; i++ )
            gusano.push_back( Coordenada( x + i, y + i ) );
}

vector< Coordenada > Gusano::obtenerGusano(){
    return gusano;
}

int Gusano::obtenerTamanio(){
    return tamanio;
}
//Debemos tener 4 estados, rotar izquierda
//Rotar derecha
//Avanzar X
//Avanzar Y
void Gusano::mover(){
    /*random_device randomDevice;
    mt19937 generator( randomDevice() );
    uniform_int_distribution<> distribution(0, 7);*/
    int random = rand() % 10;//distribution( generator );

    for( int i = tamanio - 1; i >= 1; i-- )
        gusano[ i ] = gusano[ i - 1 ];

    switch ( random ){
        case 0:
            gusano[ 0 ].incrementaX();
        break;
        
        case 1:
            gusano[ 0 ].incrementaY();
        break;

        case 2:
            gusano[ 0 ].incrementaXY();
        break;

        case 3:
            gusano[ 0 ].decrementaX();
        break;

        case 4:
            gusano[ 0 ].decrementaY();
        break;

        case 5:
            gusano[ 0 ].decrementaXY();
        break;

        case 6:
            gusano[ 0 ].decrementaYincX();
        break;

        case 7:
            gusano[ 0 ].decrementaYincX();
        break;

        case 8:
            gusano[ 0 ].decrementaXincY();
        break;

        default:
            gusano[ 0 ].decrementaXincY();
        break;
    }

}