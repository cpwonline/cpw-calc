#ifndef CALC_H
#define CALC_H

#include <iostream>

class calc
{
    public:
        // Instances
            bool error;

        // Methods
            calc();
            float getResult();
            float getBuffer();
            float getHistorial();

            void setResult(float r);
            void setBuffer(float b);
            void setHistorial(float h);

            float sum(float a, float b);
            float subtract(float a, float b);
            float multiplicate(float a, float b);
            float divide(float a, float b);

    protected:

    private:
        float result;
        float buffer;
        float historial;
};

#endif // CALC_H
