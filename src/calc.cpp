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
    short calc::getCurrentOperationSize() const
    {
        return currentOperationSize;
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

        for(int a = 0; a < sizeChar; a++) std::cout << "\n Current2[" << a << "]: " << currentOperation[a];
        currentOperation = op;
    }
    void calc::setCurrentOperationSize(short sizeOp)
    {
        std::cout << "\nEstamos en setCurrentOperationSize, sizeOp: " << sizeOp;

        currentOperationSize = sizeOp;
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
        /*std::cout << "Split operations: \n ";

        char** listOp;
        short contCharOp = 0, sizeListOp = 0, sizeListOp2 = 0, contSigns = 0;
        short contListOp = 0, beginNewOp = 0, sizeOp = getCurrentOperationSize();

        std::cout << "El tamaño del array de la operación actual es: " << sizeOp << "\n";

        //
        for(int a = 0; a < sizeOp; a++)
        {
            std::cout << "\nEstamos en " << a << ", valor: " << currentOperation[a];

            if(currentOperation[a] == '+' || currentOperation[a] == '-' || currentOperation[a] == 'x' || currentOperation[a] == '/')
                {contSigns++;std::cout << " -Signo: " << currentOperation[a];}
        }

        std::cout << "\nHay signos: " << contSigns << "\n";

        sizeListOp = contSigns * 2 + 1;

        std::cout << "\nTamaño de la listaOp: " << sizeListOp << "\n";

        listOp = new char*[sizeListOp];

        // Vamos guardando valores hasta encontrar un signo
            do
            {
                std::cout << "\n Entramos al do while. current[contCharOp] vale: " << currentOperation[contCharOp] << "\n";
                if(currentOperation[contCharOp] == 'x')
                {
                    /* Cuando encontramos un signo, empezamos a guardar todo lo anterior encontrado *
                    listOp[contListOp] = new char[sizeListOp2];
                    for(short a = 0; beginNewOp < sizeListOp2; beginNewOp++, a++)
                    {
                        std::cout << "\n begin=" << beginNewOp << ", Guardamos " << currentOperation[beginNewOp];
                        listOp[sizeListOp][a] = currentOperation[beginNewOp]; // Guardamos
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
            for(short a = 0; a < sizeListOp; a++)
                    std::cout << "listOp[" << a << "]: " << listOp[a] << "\n";


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
