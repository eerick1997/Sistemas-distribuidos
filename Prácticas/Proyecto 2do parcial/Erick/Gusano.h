#include "Coordenada.h"
#include <vector>

#ifndef GUSANO_H_
#define GUSANO_H_
class Gusano{
    private:
        std::vector< Coordenada > gusano;
        int tamanio, modulo_x, modulo_y, offset, multiplicador;
    public:
        Gusano( int, int, int );
        int obtenerTamanio();
        std::vector< Coordenada > mover();
        std::vector< Coordenada > obtenerCurva( int, int, int, int, bool );
        int obtenerCentroX( int, int );
        int obtenerCentroY( );
};
#endif