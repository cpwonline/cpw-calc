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

        char** listOp;

        short contCharOp = 0, sizeListOp = 0, contListOp = 0, beginNewOp = 0;
        bool saveEveryOp = false;

        short sizeOp = sizeof (currentOperation) / sizeof (currentOperation[0]);
        std::cout << "El tamaño del array de la operación actual es: " << sizeOp << "\n";

        //
        short contSigns = 0;
        for(int a = 0; a < sizeOp; a++)
        {
            if(currentOperation[a] == '+' || currentOperation[a] == '-' || currentOperation[a] == 'x' || currentOperation[a] == '/')
                contSigns++;
        }

        sizeListOp = sizeListOp * 2 + 1;
        listOp = new char*[sizeListOp];

        // Vamos guardando valores hasta encontrar un signo
            do
            {
                std::cout << "\n Entramos al do while. current[contCharOp] vale: " << currentOperation[contCharOp] << "\n";
                if(currentOperation[contCharOp] == 'x')
                {
                    /* Cuando encontramos un signo, empezamos a guardar todo lo anterior encontrado */
                    new listOp[contListOp][sizeListOp2];
                    for(short a = 0; beginNewOp < sizeListOp2; beginNewOp++, a++)
                    {
                        std::cout << "\n begin=" << beginNewOp << ", Guardamos " << currentOperation[beginNewOp];
                        listOp[sizeListOp2][a] = currentOperation[beginNewOp]; // Guardamos
                    }
                    contListOp++;
                }
                else
                {
                    sizeListOp2++;
                    std::cout << "\n SizeListOp2 vale: " << sizeListOp2 << "\n";
                }
                contCharOp++;
            }while(contCharOp < sizeOp);

            std::cout << "Se guardó: \n";
            for(short a = 0; a < (sizeof(listOp) / sizeof(listOp[0])); a++)
                for(short b = 0; b < (sizeof(listOp[a]) / sizeof(listOp[a][0])); b++)
                    std::cout << "listOp[" << a << "][" << b << "]: " << listOp[a][b];


            /*while(contChartOp < sizeOp)
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
