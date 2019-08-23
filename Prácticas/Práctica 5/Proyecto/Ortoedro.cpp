#include "Ortoedro.h"

Ortoedro::Ortoedro( Coordenada origen, Coordenada opuesto ) {
    //Izquierda
    Caras.push_back( Rectangulo( Coordenada( opuesto.obtenX(), origen.obtenY, opuesto.obtenZ() ), origen ) );
    //Arriba
    Caras.push_back( Rectangulo( Coordenada( origen.obtenX(), origen.obtenY(), opuesto.obtenZ() ), opuesto ) );
    //Derecha
    Caras.push_back( Rectangulo( opuesto, Coordenada( origen.obtenX(), opuesto.obtenY(), origen.obtenZ() ) ) );
    //Abajo
    Caras.push_back( Rectangulo( origen, Coordenada( opuesto.obtenX(), opuesto.obtenY(), origen.obtenZ() ) ) );
    //Fondo
    Caras.push_back( Rectangulo( Coordenada( origen.obtenX(), origen.obtenY(), opuesto.obtenZ() ), Coordenada( origen.obtenX(), opuesto.obtenY(), origen.obtenZ() ) ) );
    //Frente
    Caras.push_back( Rectangulo( Coordenada( opuesto.obtenX(), origen.obtenY(), opuesto.obtenZ() ), Coordenada( opuesto.obtenX(), opuesto.obtenY(), origen.obtenZ() ) ) );
}
vector< Coordenada > Ortoedro::obtieneVertices(){
    return Caras;
}
double obtieneArea(){

}

double obtieneVolumen(){
    
}

