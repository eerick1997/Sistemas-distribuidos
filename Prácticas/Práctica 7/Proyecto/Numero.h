#ifndef NUMERO_H_
#define NUMERO_H_
typedef long long int lli;

class Numero{
    private:
        lli numero;
        bool esPrimo;
    public:
        Numero( bool = true );
        void ponNumero( lli );
        void ponEsPrimo( bool );
        lli obtenNumero();
        bool obtenEsPrimo();
};
#endif