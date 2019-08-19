#include "Fraccion.h"
#include <bits/stdc++.h>

using namespace std;

Fraccion::Fraccion( int numerador, int denominador ){
    this -> numerador = numerador;
    this -> denominador = denominador;
}

double Fraccion::getResultado(){
    return (double)(numerador / denominador); 
}

string Fraccion::reducirFraccion(){
    string ans = "";
    int GCD = __gcd( numerador, denominador );
    ans = to_string(numerador / GCD);
    ans += "/" + to_string( denominador / GCD );
    return ( ans );
}