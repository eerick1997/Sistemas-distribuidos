#include <iostream>
using namespace std;

int main( ){
    double c = 20;
    double f;
    f = (static_cast<double> (9) / static_cast<double>(5)) * c + static_cast<double>(32); //punto 4 //Utilizando static_cast;
    cout << f << endl;
    return 0;
}