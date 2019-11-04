#include "SocketMulticast.h"
#include "SocketDatagram.h"
#include "PaqueteDatagrama.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
	string ipMulticast, cadena;
	int puerto, ttl;
	int datos[2];
	datos[0] = 4;
	datos[1] = 5;
	puerto = 7200; ttl = 1;
	SocketMulticast s(puerto);
	PaqueteDatagrama a((char *)datos, 2 * sizeof(int), "224.0.0.1", puerto);
	while(s.envia(a, ttl) > 0) {
		
		char result[sizeof(int)];
		int num[1];
		PaqueteDatagrama d(sizeof(int));
		SocketDatagrama c(8080);

		int n = c.recibe(d);
		memcpy(num, d.obtieneDatos(), sizeof(int));
		printf("Result %d \n",num[0]);
	}
	return 0;
}