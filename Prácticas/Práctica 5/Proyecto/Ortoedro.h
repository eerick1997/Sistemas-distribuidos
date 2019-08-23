#include "Rectangulo.h"
#include <bits/stdc++.h>

using namespace std;

#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_
class Ortoedro{
    private:
        vector< Rectangulo > Caras;

    public:
        Ortoedro( Coordenada origen, Coordenada opuesto );
        vector< Coordenada > obtieneVertices();
        double obtieneArea();
        double obtieneVolumen();
};
#endif