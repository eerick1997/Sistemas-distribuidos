#include "Coordenada.h"

Coordenada::Coordenada( double xx, double yy ) : x(xx), y(yy) {}

double Coordenada::obtenerY(){
    return y;
}

double Coordenada::obtenerX(){
    return x;
}