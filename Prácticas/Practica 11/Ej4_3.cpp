#include <bits/stdc++.h>
#include <iostream>
#include <thread>
using namespace std;
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
int main(){
    thread th1(CPU), th2(CPU);
    th1.join();
    th2.join();
    exit(0);
}