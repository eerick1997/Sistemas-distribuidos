#include <bits/stdc++.h>
#include <iostream>
#include <thread>
using namespace std;
#define numeroElementos 100000000
void RAM(){
    int *arreglo, i;
    arreglo = new int[numeroElementos];
    for(i = 0; i < numeroElementos; i++)
        arreglo[i] = 0;
    for(i = 0; i < 100000000; i++){
        arreglo[rand()%numeroElementos] = rand();
    }
}
void CPU(){
    double i = 0;
	int Max = 10000000;
	double seno, coseno, tangente, logaritmo, raizCuad;
	while (i < Max){
		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log (i);
		raizCuad += sqrt(i);
		i++;
	}
}
void DD(){ //AQui va lo de DD

}
int main(){
    thread th1(RAM), th2(CPU), th3(DD);
    th1.join();
    th2.join();
    th3.join();
    exit(0);
}