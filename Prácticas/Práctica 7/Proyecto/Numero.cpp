#include "Numero.h"

typedef long long int lli;

Numero::Numero( bool ){}

void Numero::ponNumero( lli Numero ){
    numero = Numero;
}

void Numero::ponEsPrimo( bool EsPrimo ){
    esPrimo = EsPrimo;
}

bool Numero::obtenEsPrimo(){
    return esPrimo;
}

lli Numero::obtenNumero(){
    return numero;
}