#include "Coordenada.h"
#include <vector>

#ifndef GUSANO_H_
#define GUSANO_H_
class Gusano{
    private:
        std::vector< Coordenada > cuerpo;
        int tamanio;
    
    public:
        Gusano( int );
        std::vector< Coordenada > obtenerGusano();
        int obtenerTamanio();
        void rotarIzquierda();
        void rotarDerecha();
};
#endif