#include "Ortoedro.h"
/**
 * Author: Erick Efraín Vargas Romero
 * Date: 25 / 08 / 2019
*/
#include <bits/stdc++.h>

using namespace std;

Ortoedro::Ortoedro( Coordenada origen, Coordenada opuesto ) {
    //Izquierda
    Caras.push_back( Rectangulo( Coordenada( opuesto.obtenX(), origen.obtenY(), opuesto.obtenZ() ), origen ) );
    //Arriba
    Caras.push_back( Rectangulo( Coordenada( origen.obtenX(), origen.obtenY(), opuesto.obtenZ() ), opuesto ) );
    //Derecha
    Caras.push_back( Rectangulo( opuesto, Coordenada( origen.obtenX(), opuesto.obtenY(), origen.obtenZ() ) ) );
    //Abajo
    Caras.push_back( Rectangulo( origen, Coordenada( opuesto.obtenX(), opuesto.obtenY(), origen.obtenZ() ) ) );
    //Fondo
    Caras.push_back( Rectangulo( Coordenada( origen.obtenX(), origen.obtenY(), opuesto.obtenZ() ), Coordenada( origen.obtenX(), opuesto.obtenY(), origen.obtenZ() ) ) );
    //Frente
    Caras.push_back( Rectangulo( Coordenada( opuesto.obtenX(), origen.obtenY(), opuesto.obtenZ() ), Coordenada( opuesto.obtenX(), opuesto.obtenY(), origen.obtenZ() ) ) );
}

vector< Coordenada > Ortoedro::obtieneVertices(){
    vector< Coordenada > vertices;
    vertices.push_back( Caras[ 0 ].obtenSupIzquierda() );
    vertices.push_back( Caras[ 0 ].obtenInfDerecha() );
    vertices.push_back( Caras[ 1 ].obtenSupIzquierda() );
    vertices.push_back( Caras[ 1 ].obtenInfDerecha() );
    vertices.push_back( Caras[ 2 ].obtenInfDerecha() );
    vertices.push_back( Caras[ 3 ].obtenInfDerecha() );
    vertices.push_back( Caras[ 5 ].obtenSupIzquierda() );
    vertices.push_back( Caras[ 5 ].obtenInfDerecha() );
    return vertices;
}
double Ortoedro::obtieneArea(){
    double X, Y, Z;
    X = abs( Caras[ 5 ].obtenInfDerecha().obtenX() - Caras[ 4 ].obtenInfDerecha().obtenX() );
    Y = abs( Caras[ 0 ].obtenInfDerecha().obtenY() - Caras[ 2 ].obtenInfDerecha().obtenY() );
    Z = abs( Caras[ 1 ].obtenInfDerecha().obtenZ() - Caras[ 3 ].obtenInfDerecha().obtenZ() );
    return ( ( 2 * X * Y ) + ( 2 * Y * Z ) + ( 2 * X * Z ) );
}

double Ortoedro::obtieneVolumen(){
    double X, Y, Z;
    X = abs( Caras[ 5 ].obtenInfDerecha().obtenX() - Caras[ 4 ].obtenInfDerecha().obtenX() );
    Y = abs( Caras[ 0 ].obtenInfDerecha().obtenY() - Caras[ 2 ].obtenInfDerecha().obtenY() );
    Z = abs( Caras[ 1 ].obtenInfDerecha().obtenZ() - Caras[ 3 ].obtenInfDerecha().obtenZ() );
    return ( X * Y * Z );
}

