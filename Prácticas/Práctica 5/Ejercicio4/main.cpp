#include "Rectangulo.h"
#include <bits/stdc++.h>

#define PI acos( -1 )
const double RAD = 0.0174533;

using namespace std;

int main() {
    Rectangulo rectangulo1( Coordenada( sqrt( 13 ) , 56.30 * RAD ), Coordenada( sqrt( 26 ), 11.3099 * RAD ) );
    double ancho, alto;
    cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartensiano: \n";
    rectangulo1.imprimeEsq();
    cout << "El área del rectángulo es = " << rectangulo1.obtieneArea() << endl;
    return 0;
}