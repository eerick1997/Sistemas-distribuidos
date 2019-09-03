#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

void funcion( int valor ){
    cout << "Hilo " << this_thread::get_id() << " Valor recibido: " << valor << endl;
    sleep( 2 );
}

int main(){
    thread thread1( funcion, 5 ), thread2( funcion, 10 );
    cout << "Proceso principal en espera que los hilos terminen\n";
    thread1.join();
    thread2.join();
    cout << "El hilo principal termina \n";
    exit( 0 );
}