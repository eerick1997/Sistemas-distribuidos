#include "Coordenada.h"
#include <bits/stdc++.h>

#ifndef GUSANO_H_
#define GUSANO_H_
class Gusano{
    private:
        std::vector< Coordenada > gusano;
        int tamanio;

    public:
        Gusano( int, double, double, int );
        std::vector< Coordenada > obtenerGusano();
        int obtenerTamanio();
        void mover();
};
#endif