#include <bits/stdc++.h>

using namespace std;

int main(){
    int segundos;
    int horas, minutos;

    cin >> segundos;
    horas = (segundos / 3600);
    segundos -= (horas * 3600);
    minutos = (segundos / 60);
    segundos -= (minutos * 60);
    cout << horas << " horas " << minutos << " minutos " << segundos << " segundos";
    return 0;
}