#include <bits/stdc++.h>
#include "Coordenada.h"

Coordenada::Coordenada( double xx, double yy ) : x(xx), y(yy) {}

double Coordenada::obtenerX(){
    return x;
}

double Coordenada::obtenerY(){
    return y;
}

void Coordenada::aniadeMagnitud( double mag ) {
    magnitud = mag;
}

double Coordenada::obtenerMagnitud(){
    return magnitud;
}