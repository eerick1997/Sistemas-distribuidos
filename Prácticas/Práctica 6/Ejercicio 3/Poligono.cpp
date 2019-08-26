#include "Poligono.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

lli Poligono::nVertices = 0;

Poligono::Poligono(){
}

void Poligono::aniadeVertice(Coordenada coordenada){
    int m = random() % 1000;
    for( int i = 0; i < m; i++ )
        vertices.push_back( coordenada );
    nVertices += m;
}

void Poligono::aniadeVerticesRandom(){
    int m = random() % 1000;
    vertices.reserve( m );
    nVertices += m;
}

void Poligono::imprimeVertices(){
    for( int i = 0; i < vertices.size(); i++ ){
        cout << (i + 1) << " vertice ( " << vertices[ i ].obtenerX() << ", " << vertices[ i ].obtenerY() << " )" << endl;
    }
}

void Poligono::imprimeNVertices(){
    cout << nVertices << endl;
}

