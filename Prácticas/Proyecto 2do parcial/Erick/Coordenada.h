#ifndef COORDENADA_H_
#define COORDENADA_H_H
class Coordenada{
    private:
        double x, y;
    
    public:
        Coordenada();
        Coordenada( double, double );
        double obtenerX();
        double obtenerY();
        void ponerX( double );
        void ponerY( double );
};
#endif