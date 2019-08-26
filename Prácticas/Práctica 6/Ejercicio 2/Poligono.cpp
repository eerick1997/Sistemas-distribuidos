#include "Poligono.h"
#include <bits/stdc++.h>

using namespace std;

void Poligono::anadieVertice( Coordenada coordenada ){
    vertices.push_back( coordenada );
}

void Poligono::imprimeVertices(){
    for( int i = 0; i < vertices.size(); i++ ){
        cout << (i + 1) << " vertice ( " << vertices[ i ].obtenerX() << ", " << vertices[ i ].obtenerY() << " )" << endl;
    }
}