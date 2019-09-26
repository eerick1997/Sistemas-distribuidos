#include "Coordenada.h"
#include <bits/stdc++.h>

using namespace std;

Coordenada::Coordenada( double X, double Y ) : x(X), y(Y){}

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

void Coordenada::incrementaX(){
    x++;
}

void Coordenada::incrementaY(){
    y++;
}

void Coordenada::incrementaXY(){
    x++, y++;
}

void Coordenada::decrementaX(){
    if( x > 0 )
        x--;
}

void Coordenada::decrementaY(){
    if( y > 0 )
        y--;
}

void Coordenada::decrementaXY(){
    if( x > 0 && y > 0)
        x--, y--;
}

void Coordenada::decrementaXincY(){
    if( x > 0 )
        x--;
    y++;
}

void Coordenada::decrementaYincX(){
    if( y > 0 )
        y--;
    x++;
}