#include "calc.h"
#include <iostream>

// Constructor
    calc::calc()
    {
        setResult(0.00);
        setBuffer(0.00);
        setHistorial(0.00);
        error = false;
    }

// Getters
    float calc::getResult()
    {
        return result;
    }
    float calc::getBuffer()
    {
        return buffer;
    }
    float calc::getHistorial()
    {
        return historial;
    }
    char[] calc::getCurrentOperation()
    {
        return currentOperation;
    }

// Setters
    void calc::setResult(float r)
    {
        result = r;
    }
    void calc::setBuffer(float b)
    {
        buffer = b;
    }
    void calc::setHistorial(float h)
    {
        historial = h;
    }
    void calc::setCurrentOperation(char op[])
    {
        short sizeChar = sizeof(op) / sizeof(op[0]);
        currentOperation = new char[sizeChar];

        std::cout << "En la función \n Tamaño: " << sizeChar;
        currentOperation = op;
    }

// Members
    float calc::sum(float a, float b)
    {
        return a + b;
    }
    float calc::subtract(float a, float b)
    {
        return a - b;
    }
    float calc::multiplicate(float a, float b)
    {
        return a * b;
    }
    float calc::divide(float a, float b)
    {
        if(b != 0)
            return a / b;
        else
        {
            error = true;
            return 0.0;
        }
    }
