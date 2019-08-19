#ifndef TEMPERATURA_H_
#define TEMPERATURA_H_

class Temperatura{
    private:
        float kelvin;
    public:
        void setTempKelvin( float kelvin );
        void setTempFahrenheit( float fahrenheit );
        void setTempCelsius( float celsius );
        float getTempKelvin();
        float getTempFahrenheit();
        float getTempCelsius();
};

#endif