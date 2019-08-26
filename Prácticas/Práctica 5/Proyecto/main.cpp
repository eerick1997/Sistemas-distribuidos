#include "Ortoedro.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    int i = 0;
    Ortoedro ortoedro( Coordenada( 0, 0, 0 ), Coordenada( 2, 3, 4 ) );
    vector< Coordenada > vertices = ortoedro.obtieneVertices();
    cout << "Area: " << ortoedro.obtieneArea() << endl;
    cout << "Volumen: " << ortoedro.obtieneVolumen() << endl;
    for( auto vertice : vertices ){
        cout << "\n" << ++i << " vértice (" << vertice.obtenX() << ", " << vertice.obtenY() << ", " << vertice.obtenZ() << ")";
    }
    cout << endl;
    return 0;
}