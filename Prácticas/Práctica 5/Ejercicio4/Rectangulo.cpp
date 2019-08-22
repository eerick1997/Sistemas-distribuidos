
#include "Rectangulo.h"
#include "Coordenada.h"
#include <bits/stdc++.h>

using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0, 0), inferiorDer(0,0){}

Rectangulo::Rectangulo( double xSupIzq, double ySupIzq, double xInfDer, double yInfDer ) : superiorIzq( xSupIzq, ySupIzq ), inferiorDer( xInfDer, yInfDer ){}

Rectangulo::Rectangulo( Coordenada supIzq, Coordenada infDer ) : superiorIzq( supIzq ), inferiorDer( infDer ){}

void Rectangulo::imprimeEsq(){
    cout << "Para la esquina superior derecha. \n";
    cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
    cout << "Para la esquina superior derecha. \n";
    cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

Coordenada Rectangulo::obtieneSupIzq(){
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
    return inferiorDer;
}

double Rectangulo::obtieneArea(){
    double alto = obtieneSupIzq().obtenerY() - obtieneInfDer().obtenerY();
    double ancho = obtieneInfDer().obtenerX() - obtieneSupIzq().obtenerX();
    return alto * ancho;
}