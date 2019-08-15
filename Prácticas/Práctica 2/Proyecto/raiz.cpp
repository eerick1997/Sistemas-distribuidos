#include <bits/stdc++.h>
#define LIM 0.00001
using namespace std;

int main(){
    double n;
    cin >> n;
    if( n < 0 )
        cout << "La solucion no está en el conjunto de los reales" << endl;
    else {
        double b = n, h = 1;
        while( (b - h) > LIM ){ 
            b = (h + b) / 2;
            h = n / b;
        }
        cout << b << endl;
    }
    return 0;
}