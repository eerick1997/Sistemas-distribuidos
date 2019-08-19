#include "Fecha.h"
#include <iostream>
using namespace std;
int Fecha::convierte(){
    return anio*10000 + mes*100 + dia;
}