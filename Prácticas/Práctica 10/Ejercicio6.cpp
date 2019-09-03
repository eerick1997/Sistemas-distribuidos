#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int variable = 0;
mutex m;

void funcionIncrementa( int n ){
    m.lock();
    while( n-- )
        variable++;
    sleep( 1 );
    m.unlock();
}

void funcionDecrementa( int n ){
    m.lock();
    while( n-- )
        variable--;
    sleep( 1 );
    m.unlock();
}

int main(){
    int n;
    cin >> n;
    thread thread1( funcionIncrementa, n ), thread2( funcionDecrementa, n );
    cout << "Hilo principal en espera...\n";
    thread1.join();
    thread2.join();
    cout << "Hilo principal termina\n";
    cout << "variable: " << variable << endl;
}