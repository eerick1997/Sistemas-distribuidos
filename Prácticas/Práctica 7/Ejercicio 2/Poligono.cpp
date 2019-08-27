#include "Poligono.h"
#include <bits/stdc++.h>

using namespace std;

void Poligono::anadieVertice( Coordenada coordenada ){
    vertices.push_back( coordenada );
    Coordenada origen( 0, 0 ); 
    double mag = pow( coordenada.obtenerX() - origen.obtenerX(), 2 );
    mag += pow( coordenada.obtenerY() - origen.obtenerY(), 2 );
    vertices[ vertices.size() - 1 ].aniadeMagnitud( sqrt( mag ) );
}

void Poligono::imprimeVertices(){
    int ii = 1;
    cout << fixed;
    cout << setprecision(3);
    
    for( vector< Coordenada >::iterator i = vertices.begin(); i != vertices.end(); i++, ii++ ){
        cout << ii << " vertice (" << i -> obtenerX() << ",  " << i -> obtenerY() << ") " << " magnitud = " << i -> obtenerMagnitud() << endl;
    }
}

bool ordenaA( Coordenada A, Coordenada B){
    return ( A.obtenerMagnitud() < B.obtenerMagnitud() );
}

void Poligono::OrdenarVertices(){
    sort( vertices.begin(), vertices.end(), ordenaA );
}