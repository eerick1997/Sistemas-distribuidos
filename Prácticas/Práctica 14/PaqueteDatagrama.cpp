#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>

using namespace std;

PaqueteDatagrama::PaqueteDatagrama( char *datos, unsigned int longitud, char *dirIP, int puerto ){
    this -> datos = datos;
    this -> longitud = longitud;
    this -> datos = new char[ longitud ];
    this -> datos = datos; 
    memcpy( this -> ip, dirIP, sizeof( dirIP ) );
    this -> puerto = puerto;
}

PaqueteDatagrama::PaqueteDatagrama( unsigned int longitud ){
    this -> longitud = longitud;
    this -> datos = new char[ longitud ];
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
    memcpy( ip, IP, sizeof( IP ) );
}

void PaqueteDatagrama::inicializaDatos( char *datos ){
    this -> datos = new char[ longitud ];
    this -> datos = datos;
}

PaqueteDatagrama::~PaqueteDatagrama(){
    delete[] datos;
}