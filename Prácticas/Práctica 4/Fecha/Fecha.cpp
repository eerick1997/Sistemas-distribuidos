#include "Fecha.h"
#include <bits/stdc++.h>

using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa) : dia(dd), mes(mm), anio(aaaa){
    if( ( mes < 1 ) || ( mes > 12 ) || ( 1 < dia || dia > 31 ) || ( 0 < anio || anio > 2019 )){
        cout << "Hay algún valor ilegal!\n";
        exit( 1 );
    }
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa){
    anio = aaaa;
    mes = mm;
    dia = dd;
    return;
}

void Fecha::muestraFecha(){
    cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    return;
}
