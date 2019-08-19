#include "Fraccion.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Fraccion fraccion(18, 15);
    cout << fraccion.getResultado() << endl;
    cout << fraccion.reducirFraccion() << endl;
    return 0;
}