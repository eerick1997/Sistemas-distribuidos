#include <bits/stdc++.h>
#include "PaqueteDatagrama.h"
#include "SocketMulticast.h"
#include "SocketDatagram.h"
#include <cstring>
using namespace std;

int main(){

	//char* ip_multicast;
	int puerto;
	int recibe;
	int numeros[2];

	PaqueteDatagrama p(sizeof(int)*4);

	//cin >> puerto;

	SocketMulticast socket_multicast(7200);

	socket_multicast.unirseGrupo("224.0.0.1");

	recibe= socket_multicast.recibe(p);
	memcpy(numeros, p.obtieneDatos(), sizeof(int)*2);

	cout << numeros[ 0 ] << " | " << numeros[ 1 ];

	int resp= numeros[0]+numeros[1];

	char aux[16] = "";
	char *ip3 = p.obtieneDireccion();

	strcat(aux, to_string((int)(unsigned char)ip3[0]).c_str());
	strcat(aux, ".");
	strcat(aux, to_string((int)(unsigned char)ip3[1]).c_str());
	strcat(aux, ".");
	strcat(aux, to_string((int)(unsigned char)ip3[2]).c_str());
	strcat(aux, ".");
	strcat(aux, to_string((int)(unsigned char)ip3[3]).c_str());

	SocketDatagrama sd(8080);
	
	PaqueteDatagrama pd((char*)&resp, sizeof(int), aux, 8080);
	sd.envia(pd);


	return 0;
}