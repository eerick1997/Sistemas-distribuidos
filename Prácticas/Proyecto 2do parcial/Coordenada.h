#ifndef COORDENADA_H_
#define COORDENADA_H_H
class Coordenada{
    private:
        double x, y;
    
    public:
        Coordenada( int, int );
        double obtenerX();
        double obtenerY();
        void ponerX( double X );
        void ponerY( double Y );
};
#endif