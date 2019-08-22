#include <bits/stdc++.h>

using namespace std;

class Fecha{
    public:
        int dia;
        int mes;
        int anio;
        char s[1000000];
    public:
        Fecha(int = 3, int = 4, int = 2014);
        void inicializaFecha(int, int, int);
        void muestraFecha();
};

Fecha::Fecha(int dd, int mm, int aaaa){
    mes = mm;
    dia = dd;
    anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
}

void Fecha::muestraFecha(){
    cout << "La fecha es (dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    return;
}


int masVieja(Fecha fecha1, Fecha fecha2){
    if( fecha1.anio > fecha2.anio )
        return 1;
    else if( fecha2.anio > fecha1.anio )
        return 2;
    else if( fecha1.anio == fecha2.anio && fecha1.mes > fecha2.mes)
        return 1;
    else if( fecha1.anio == fecha2.anio && fecha2.mes > fecha1.mes)
        return 2;
    else if( fecha1.anio == fecha2.anio && fecha1.mes == fecha2.mes && fecha1.dia > fecha2.dia )
        return 1;
    else 
        return 2;
    return 1;
}

int masViejaR(Fecha *fecha1, Fecha *fecha2){
    if( fecha1 -> anio > fecha2 -> anio )
        return 1;
    else if( fecha2 -> anio > fecha1 -> anio )
        return 2;
    else if( fecha1 -> anio == fecha2 -> anio && fecha1 -> mes > fecha2 -> mes)
        return 1;
    else if( fecha1 -> anio == fecha2 -> anio && fecha2 -> mes > fecha1 -> mes)
        return 2;
    else if( fecha1 -> anio == fecha2 -> anio && fecha1 -> mes == fecha2 -> mes && fecha1 -> dia > fecha2 -> dia )
        return 1;
    else 
        return 2;
    return 1;
}

int main(){
    Fecha a, b( 20, 2, 2019 );
    int n = 1000;
    
    srand(time(NULL));

    while( n-- ){

        int dia1 = rand() % 31 + 1;
        int mes1 = rand() % 12 + 1;
        int anio1 = rand();

        int dia2 = rand() % 31 + 1;
        int mes2 = rand() % 12 + 1;
        int anio2 = rand();
        
        a.inicializaFecha( dia1, mes1, anio1 );
        b.inicializaFecha( dia2, mes2, anio2 );
        //cout << sizeof( a.s ) << endl;
        masViejaR( &a, &b );
        //cadena( a.s );
        //a.muestraFecha();
        //b.muestraFecha();
        //cout << masVieja( a, b ) << endl;

    }

    //cout << (double)((double)(clock() - time_start) / CLOCKS_PER_SEC) << endl;
    return 0;
}