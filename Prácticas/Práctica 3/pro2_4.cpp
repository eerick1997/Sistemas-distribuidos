#include "Fecha.h"
#include <iostream>
using namespace std;
int main(){
    Fecha a(19, 8, 200);
    a.muestraFecha();
    if(a.leapyr()){
        cout << "Corresponde a un año bisiesto" << endl;
    }
    else{
        cout << "No corresponde a un año bisiesto" << endl;
    }
    int total = 0;
    for (int i = 1; i <= 2019; i++){
        a.inicializaFecha(1,1, i);
        if( a.leapyr()){
            total++;
        }
    }
    cout << total << endl;
}