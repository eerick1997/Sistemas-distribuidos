/**
 * Author: Erick Efraín Vargas Romero
 * Date: 25 / 08 / 2019
*/
#include "Coordenada.h"

#ifndef RECTANGULO_H_
#define RECTANGULO_H_

class Rectangulo{
    private:
        Coordenada superiorIzquierda;
        Coordenada inferiorDerecha;

    public:
        Rectangulo( Coordenada supIzquierda, Coordenada infDerecha );
        Coordenada obtenSupIzquierda();
        Coordenada obtenInfDerecha();
        double obtenerArea();
        
};

#endif