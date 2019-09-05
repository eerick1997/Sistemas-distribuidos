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
int main(){
    thread th1(RAM), th2(RAM);
    th1.join();
    th2.join();
    exit(0);
}