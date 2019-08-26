/**
 * Author: Erick Efraín Vargas Romero
 * Date: 25 / 08 / 2019
*/
#include "Rectangulo.h"
#include <bits/stdc++.h>

Rectangulo::Rectangulo( Coordenada supIzquierda, Coordenada InfDerecha ) : superiorIzquierda( supIzquierda ), inferiorDerecha( InfDerecha ){}

Coordenada Rectangulo::obtenSupIzquierda(){
    return superiorIzquierda;
}

Coordenada Rectangulo::obtenInfDerecha(){
    return inferiorDerecha;
}

double Rectangulo::obtenerArea(){
    double X = fabs( superiorIzquierda.obtenZ() - inferiorDerecha.obtenZ() );
    double Y = fabs( superiorIzquierda.obtenY() - inferiorDerecha.obtenY() );
    double Z = fabs( superiorIzquierda.obtenX() - inferiorDerecha.obtenX() );
    double area;
    if( X == 0 )
        area = Y * Z;
    else if( Y == 0 )
        area = X * Z;
    else
        area = X * Y;
    return area;
}