#ifndef CALC_H
#define CALC_H

#include <iostream>

class calc
{
    public:
        // Instances

        // Methods
            calc();
            virtual ~calc();
            float getResult();
            float getBuffer();
            float[] getHistorial();

            void setResult(float r);
            void setBuffer(float b);
            void setHistorial(float h);

            void sum(float a, float b);
            void subtract(float a, float b);
            void multiplicate(float a, float b);
            void divide(float a, float b);

    protected:

    private:
        float result;
        float buffer;
        float historial[];
};

#endif // CALC_H
