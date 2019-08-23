#include "Coordenada.h"

Coordenada::Coordenada( double xx, double yy, double zz ) : x( xx ), y ( yy ), z ( zz ){}

double Coordenada::obtenX(){
    return x;
}

double Coordenada::obtenY(){
    return y;
}

double Coordenada::obtenZ(){
    return z;
}