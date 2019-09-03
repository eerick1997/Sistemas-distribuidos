#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int variable = 0;

void funcionIncrementa( int n ){
    while( n-- )
        variable++;
    sleep( 1 );
}

void funcionDecrementa( int n ){
    while( n-- )
        variable--;
    sleep( 1 );
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