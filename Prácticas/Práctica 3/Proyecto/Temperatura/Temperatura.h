#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura{
    private:
        int kelvin;
    public:
        void setTempKelvin( int kelvin );
        void setTempFahrenheit( int fahrenheit );
        void setTempCelsius( int celsius );
        int getTempKelvin();
        int getTempFahrenheit();
        int getTempCelsius();
};

#endif