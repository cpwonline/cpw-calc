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
    float calc::getResult() const
    {
        return result;
    }
    float calc::getBuffer() const
    {
        return buffer;
    }
    float calc::getHistorial() const
    {
        return historial;
    }
    char* calc::getCurrentOperation() const
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
        int sizeChar = sizeof(op) / sizeof(op[0]);
        currentOperation = new char[sizeChar];

        std::cout << "\n En la función \n Tamaño: " << sizeChar;
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
    bool calc::splitOperations()
    {
        std::cout << "Split operations: \n ";
        char* listOp;

        short cont = 0, sizeListOp = 0, beginNewOp = 0;
        bool saveEveryOp = false;

        short sizeOp = sizeof (currentOperation) / sizeof (currentOperation[0]);
        std::cout << "El tamaño del array de la operación actual es: " << sizeOp << "\n";

        // Vamos guardando valores hasta encontrar un signo
            do
            {
                std::cout << "\n Entramos al do while. current[cont] vale: " << currentOperation[cont] << "\n";
                if(currentOperation[cont] == 'x')
                {
                    /* Cuando encontramos un signo, empezamos a guardar todo lo anterior encontrado */
                    listOp = new char[sizeListOp];
                    for(short a = 0; beginNewOp < sizeListOp; beginNewOp++, a++)
                    {
                        std::cout << "\n begin=" << beginNewOp << ", Guardamos " << currentOperation[beginNewOp];
                        listOp[a] = currentOperation[beginNewOp];
                    }
                    saveEveryOp = true;
                }
                else
                {
                    sizeListOp++;
                    std::cout << "\n SizeListOp vale: " << sizeListOp << "\n";
                }
                cont++;
            }while(saveEveryOp == false);

            std::cout << "Se guardó: " << listOp << "\n";

            /*while(cont < sizeOp)
            {

            }*/
            return true;
    }
    char* calc::convertToChar(float valor)
    {
        /*char buffer[64];
        int ret = snprintf(buffer, sizeof buffer, "%f", myFloat);

        if (ret < 0) {
            return EXIT_FAILURE;
        }
        if (ret >= sizeof buffer) {
            /* Result was truncated - resize the buffer and retry.
        }*/
    }
