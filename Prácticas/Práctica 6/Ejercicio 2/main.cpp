#include "Poligono.h"

using namespace std;

int main(){
    Poligono p;
    p.anadieVertice(Coordenada(1, 0));
    p.anadieVertice(Coordenada(1, 1));
    p.anadieVertice(Coordenada(0, 1));
    p.anadieVertice(Coordenada(1, 0));
    p.imprimeVertices();
}