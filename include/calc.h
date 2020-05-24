#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <vector>

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
            std::vector<char> getCurrentOperation() const;
            short getCurrentOperationSize() const;

            void setResult(float r);
            void setBuffer(float b);
            void setHistorial(float h);
            void setCurrentOperation(char op[], short sizeChar);

            float sum(float a, float b);
            float subtract(float a, float b);
            float multiplicate(float a, float b);
            float divide(float a, float b);
            bool splitOperations();
            short countSymbols();
            char* storeValues(short *since, short sizeListOp2);

    protected:

    private:
        float result;
        float buffer;
        float historial;
        std::vector<char> currentOperation;
        short currentOperationSize;
};

#endif // CALC_H
