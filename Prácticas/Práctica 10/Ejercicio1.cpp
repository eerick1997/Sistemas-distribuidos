#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void funcion( int valor ){
    printf("Hilo %ld Valor recibido: %d \n", this_thread::get_id(), valor);
    sleep( 2 );
}

int main(){
    thread thread1( funcion, 5 ), thread2( funcion, 10 );
    printf("Proceso principal en espera que los hilos terminen\n");
    thread1.join();
    thread2.join();
    printf("El hilo principal termina \n");
    exit( 0 );
}