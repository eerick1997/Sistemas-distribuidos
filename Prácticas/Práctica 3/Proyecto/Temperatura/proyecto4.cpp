#include "Temperatura.h"
#include <bits/stdc++.h>

using namespace std;

int main(){
    Temperatura a;
    a.setTempKelvin( 10.0 );
    cout << a.getTempKelvin() << endl;
    cout << a.getTempCelsius() << endl;
    cout << a.getTempFahrenheit() << endl;
    a.setTempFahrenheit( 10 );
    cout << a.getTempKelvin() << endl;
    cout << a.getTempCelsius() << endl;
    cout << a.getTempFahrenheit() << endl;
    a.setTempCelsius( 10 );
    cout << a.getTempKelvin() << endl;
    cout << a.getTempCelsius() << endl;
    cout << a.getTempFahrenheit() << endl;
    return 0;
}