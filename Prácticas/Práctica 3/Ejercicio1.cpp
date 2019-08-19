#include <bits/stdc++.h>

using namespace std;

class Clase{
    private:
        int attr1;
        string attr2;
        float attr3;
    public:
        int attr4;
};

int main(){
    Clase a;
    //Al ser un atributo privado no nos permite acceder a él
    a.attr1;
    //Este es un atributo público por tanto podemos acceder a él
    a.attr4;

}