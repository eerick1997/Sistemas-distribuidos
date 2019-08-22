#include <unistd.h>
#include <iostream>

using namespace std;

class NumerosRand{
    private:
        int *arreglo;
        unsigned int numerosElementos;
    public:
        NumerosRand( unsigned int num );
        void inicializaNumerosRand( void );
        ~NumerosRand();
};

NumerosRand::NumerosRand(unsigned int num){
    numerosElementos = num;
    arreglo = new int[ numerosElementos ];
}

void NumerosRand::inicializaNumerosRand(){
    unsigned int i;
    for( i = 0; i < numerosElementos; i++ ){
        arreglo[ i ] = rand();
    }
    return;
}

NumerosRand::~NumerosRand(){
    delete[] arreglo;
}

void pruebaClase(){
    unsigned int capacidad;
    cout << "Numero de enteros aleatorios en el arreglo: ";
    cin >> capacidad;
    NumerosRand tmp( capacidad );
    tmp.inicializaNumerosRand();
    sleep( 7 );
}

int main(){
    char res;
    do{
        pruebaClase();
        cout << "Probar de nuevo? (s/n) ";
        cin >> res;
    } while( ( res == 's' ) || ( res == 'S' ) ) ;
    return 0;
}