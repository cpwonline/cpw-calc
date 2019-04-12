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
            float getResult() const;
            float getBuffer() const;
            float getHistorial() const;
            char* getCurrentOperation() const;
            short getCurrentOperationSize() const;

            void setResult(float r);
            void setBuffer(float b);
            void setHistorial(float h);
            void setCurrentOperation(char op[]);
            void setCurrentOperationSize(short sizeOp);

            float sum(float a, float b);
            float subtract(float a, float b);
            float multiplicate(float a, float b);
            float divide(float a, float b);
            bool splitOperations();

            char* convertToChar(float valor);

    protected:

    private:
        float result;
        float buffer;
        float historial;
        char* currentOperation;
        short currentOperationSize;
};

#endif // CALC_H
