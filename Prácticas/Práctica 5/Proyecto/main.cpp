/**
 * Author: Erick Efraín Vargas Romero
 * Date: 25 / 08 / 2019
*/
#include "Ortoedro.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    int i = 0;
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    Ortoedro ortoedro( Coordenada( x1, y1, z1 ), Coordenada( x2, y2, z2 ) );
    vector< Coordenada > vertices = ortoedro.obtieneVertices();
    cout << "Area: " << ortoedro.obtieneArea() << endl;
    cout << "Volumen: " << ortoedro.obtieneVolumen() << endl;
    for( auto vertice : vertices ){
        cout << "\n" << ++i << " vértice (" << vertice.obtenX() << ", " << vertice.obtenY() << ", " << vertice.obtenZ() << ")";
    }
    cout << endl;
    return 0;
}