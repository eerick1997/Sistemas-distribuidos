#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>

using namespace std;

PaqueteDatagrama::PaqueteDatagrama( char *datos, unsigned int longitud, char *dirIP, int puerto ){
    this -> datos = datos;
    this -> longitud = longitud;
    strcpy( ip, dirIP );
    this -> puerto = puerto;
}

char *PaqueteDatagrama::obtieneDireccion(){
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
    int puerto;
}

char *PaqueteDatagrama::obtieneDatos(){
    return datos;
}

void PaqueteDatagrama::inicializaPuerto( int puerto ){
    this -> puerto = puerto;
}

void PaqueteDatagrama::inicializaIp( char *IP ){
    strcpy( ip, IP );
}

void PaqueteDatagrama::inicializaDatos( char *datos ){
    strcpy( this -> datos, datos );
}