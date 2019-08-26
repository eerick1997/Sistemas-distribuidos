#include "Poligono.h"

using namespace std;

int main(){
        vector< Poligono > poligonoIrregular( 1000 );
        for( auto i = 0; i < poligonoIrregular.size(); i++ ){
                poligonoIrregular[ i ].aniadeVertice( Coordenada(0,0) );
                //poligonoIrregular[ i ].aniadeVerticesRandom();
        }
        
        poligonoIrregular[ poligonoIrregular.size() - 1].imprimeNVertices();
}