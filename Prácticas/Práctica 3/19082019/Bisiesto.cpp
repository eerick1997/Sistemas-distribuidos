#include "Fecha.h"
#include <iostream>
using namespace std;
bool Fecha::leapyr(){
    if(anio%400 == 0)
        return true;
    
    else if(anio%4 == 0 && anio%100 != 0 ){
        return true;
    }
    return false;
}