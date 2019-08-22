#include "Rectangulo.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Rectangulo rectangulo1( Coordenada( 2, 3 ), Coordenada(5, 1) );
    double ancho, alto;
    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartensiano: \n";
    rectangulo1.imprimeEsq();
    cout << "El área del rectángulo es = " << rectangulo1.obtieneArea() << endl;
    return 0;
}