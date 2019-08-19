#include "Fecha.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Fecha a(19, 8, 2000);
    int count = 0;
    for( int i = 1; i <= 2019; i++ ){
        a.inicializaFecha(1, 1, i);
        if( a.leapyr() )
            count++;
    }
    cout << count << endl;
    //cout << (a.leapyr() ? "True" : "false") << endl;
    return 0;
}