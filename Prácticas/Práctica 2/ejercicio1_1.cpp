#include <iostream>
using namespace std;

int main( ){
    double c = 20;
    double f;
    // f = ( 9.0 / 5.0 ) * c + 32; // punto 3
    f = (static_cast<double> (9) / static_cast<double>(5)) * c + static_cast<double>(32); //punto 4
    cout << f << endl;
    return 0;
}