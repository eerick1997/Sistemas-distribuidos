#include "Coordenada.h"
#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;

#ifndef POLIGONO_H_
#define POLIGONO_H_

class Poligono{
    private:
        vector< Coordenada > vertices;
        static lli nVertices;
    
    public:
        Poligono();
        void aniadeVertice(Coordenada coordenada);
        void aniadeVerticesRandom();
        void imprimeVertices();
        static void imprimeNVertices();
};

#endif