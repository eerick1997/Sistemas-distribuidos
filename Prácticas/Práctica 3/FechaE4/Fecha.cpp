#include "Fecha.h"
#include <bits/stdc++.h>

using namespace std;

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

int Fecha::convierte(){
    return anio * 10000 + mes * 100 + dia;
}

void Fecha::muestraFecha(){
    cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    return;
}

bool Fecha::leapyr(){
    return ( ( (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0) ) );
}
