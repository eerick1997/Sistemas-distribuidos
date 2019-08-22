#include "Coordenada.h"
#include <iostream>
using namespace std;
class Rectangulo{
    private:
    Coordenada superiorIzq;
    Coordenada inferiorDer;
    public:
    Rectangulo();
    Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
    void imprimeEsq();
    Coordenada obtieneSupIzq();
    Coordenada obtieneInfDer();
};