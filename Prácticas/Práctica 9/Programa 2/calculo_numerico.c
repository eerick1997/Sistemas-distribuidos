#include <stdlib.h>
#include<time.h>
#include<stdio.h>
#include<math.h>
#define	max 10000000

int main(){

	double i = 0;
	float seno,coseno,tangente,logaritmo,raizCuad;
	printf("Calculando...\n");
	while(i<max){

		seno += sin(i);
		coseno += cos(i);
		tangente += tan(i);
		logaritmo += log(i);
		raizCuad += sqrt(i);
		i++;

		

	}

	//printf("seno %f\ncoseno%f\ntangente%f\nlogaritmo%f\n,raizCuad%f\n",seno,coseno,tangente,logaritmo,raizCuad );
	printf("Terminado!\n");
return 0;
}
