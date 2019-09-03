#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int n;

void funcionIncrementa( atomic< int > &variable ){
    for( int i = 0; i < n; i++ )
        variable++;
    sleep( 1 );
}

void funcionDecrementa( atomic< int > &variable ){
    for( int i = 0; i < n; i++ )
        variable--;
    sleep( 1 );
}

int main(){
    cin >> n;
    atomic< int > variable( 0 );
    thread thread1( funcionIncrementa, ref(variable) ), thread2( funcionDecrementa, ref(variable) );
    cout << "Hilo principal en espera...\n";
    thread1.join();
    thread2.join();
    cout << "Hilo principal termina\n";
    cout << "variable: " << variable << endl;
}