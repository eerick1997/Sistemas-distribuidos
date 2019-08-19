#include "Temperatura.h"
#include <bits/stdc++.h>

using namespace std;

float Temperatura::getTempKelvin(){
    return kelvin;
}

float Temperatura::getTempFahrenheit(){
    return ( (kelvin * 9 / 5) - 459.67 );
}

float Temperatura::getTempCelsius(){
    return ( kelvin - 273.15 );
}

void Temperatura::setTempKelvin( float kelvin ){
    this -> kelvin = kelvin;
}

void Temperatura::setTempFahrenheit(float fahrenheit){
    this -> kelvin = (fahrenheit + 459.67) * ( 5 / 9 );
}

void Temperatura::setTempCelsius(float celsius){
    this -> kelvin = celsius + 273.15;
}