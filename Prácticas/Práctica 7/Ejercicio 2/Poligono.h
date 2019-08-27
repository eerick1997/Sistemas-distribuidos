#include "Coordenada.h"
#include <bits/stdc++.h>

using namespace std;

#ifndef POLIGONO_H_
#define POLIGONO_H_

class Poligono{
    private:
        vector< Coordenada > vertices;
    
    public:
        void anadieVertice( Coordenada vertice );
        void imprimeVertices();
        void OrdenarVertices();
};

#endif