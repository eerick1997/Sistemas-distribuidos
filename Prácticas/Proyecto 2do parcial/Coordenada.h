#ifndef COORDENADA_H_
#define COORDENADA_H_H
class Coordenada{
    private:
        double x, y;
    
    public:
        Coordenada( double X, double Y );
        double obtenerX();
        double obtenerY();
        void ponerX( double X );
        void ponerY( double Y );
        void incrementaX();
        void incrementaY();
        void incrementaXY();
        void decrementaX();
        void decrementaY();
        void decrementaXY();
        void decrementaXincY();
        void decrementaYincX();
};
#endif