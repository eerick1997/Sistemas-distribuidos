#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int variable = 0;

void funcionIncrementa( ){
    variable++;
    sleep( 1 );
}

void funcionDecrementa( ){
    variable--;
    sleep( 1 );
}

int main(){
    thread thread1( funcionIncrementa ), thread2( funcionDecrementa );
    cout << "Hilo principal en espera...\n";
    thread1.join();
    thread2.join();
    cout << "Hilo principal termina\n";
    cout << "variable: " << variable << endl;
}