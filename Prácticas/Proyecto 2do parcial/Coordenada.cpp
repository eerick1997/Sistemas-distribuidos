#include "Coordenada.h"
#include <bits/stdc++.h>

using namespace std;

Coordenada::Coordenada( int X, int Y ) : x( X ), y( Y ){ }

double Coordenada::obtenerX(){
    return x;
}

double Coordenada::obtenerY(){
    return y;
}

void Coordenada::ponerX( double X ){
    x = X;
}

void Coordenada::ponerY( double Y ){
    y = Y;
}