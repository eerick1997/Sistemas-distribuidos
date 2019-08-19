#include <bits/stdc++.h>
#ifndef FRACCION_H_
#define FRACCION_H_

class Fraccion{
    private: 
        int numerador;
        int denominador;
    public:
        double getResultado();
        std::string reducirFraccion();
        Fraccion( int numerador , int denominador );
};

#endif