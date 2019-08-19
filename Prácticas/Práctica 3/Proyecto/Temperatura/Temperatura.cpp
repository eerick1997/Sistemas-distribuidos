#include "Temperatura.h"
#include <bits/stdc++.h>

using namespace std;

int Temperatura::getTempKelvin(){
    return kelvin;
}

int Temperatura::getTempFahrenheit(){
    return kelvin  * ( (9 / 5) - 459.67 );
}

int Temperatura::getTempCelsius(){
    return ( kelvin - 273.15 );
}

void Temperatura::setTempKelvin( int kelvin ){
    this -> kelvin = kelvin;
}

void Temperatura::setTempFahrenheit(int fahrenheit){
    this -> kelvin = (fahrenheit + 459.67) * ( 5 / 9 );
}

void Temperatura::setTempCelsius(int celsius){
    this -> kelvin = celsius + 273.15;
}