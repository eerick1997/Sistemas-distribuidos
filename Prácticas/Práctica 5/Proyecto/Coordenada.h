#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{
    private:
        double x;
        double y;
        double z;
    public:
        Coordenada( double xx, double yy, double zz );
        double obtenX();
        double obtenY();
        double obtenZ();
};

#endif