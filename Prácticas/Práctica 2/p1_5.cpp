#include <iostream>
using namespace std;

int main(){

int seg = 0, hr = 0, min = 0, segs = 0, mod = 0;
 printf("ingrese un valor entero de tiempo en segundos:\n");
 cin >> seg;

 hr = seg / 60;
 mod = seg % 60;
 min = mod / 60;
 mod = mod % 60;
 segs = mod / 60;




printf("%d horas, %d minutos y %d segundos\n", hr,min,segs ) ;
	
	return 0;
}