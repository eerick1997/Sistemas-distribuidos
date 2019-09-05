#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int main (){
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
	return 0;
}

