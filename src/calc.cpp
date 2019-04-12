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
    void calc::setCurrentOperation(char op[], short sizeChar)
    {
        currentOperation = new char[sizeChar];

        std::cout << "\n En la función \n Tamaño: " << sizeChar;

        currentOperation = op;

        for(int a = 0; a < sizeChar; a++) std::cout << "\n Current2[" << a << "]: " << currentOperation[a];

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
        std::cout << "Split operations: \n ";

        char** listOp;
        short contCharOp = 0, sizeListOp = 0, sizeListOp2 = 0, contSigns = 0;
        short contListOp = 0, since = 0, until = 0, sizeOp = getCurrentOperationSize();

        std::cout << "El tamaño del array de la operación actual es: " << sizeOp << "\n";

        // Verificamos cuántos signos hay
        for(int a = 0; a < sizeOp; a++)
        {
            std::cout << "\nEstamos en " << a << ", valor: " << currentOperation[a];

            if(currentOperation[a] == '+' || currentOperation[a] == '-' || currentOperation[a] == 'x' || currentOperation[a] == '/')
                {contSigns++;std::cout << " -Signo: " << currentOperation[a];}
        }

        std::cout << "\nHay signos: " << contSigns << "\n";

        sizeListOp = contSigns * 2 + 1; // Establecemos el tamaño de la lista

        std::cout << "\nTamaño de la listaOp: " << sizeListOp << "\n";

        listOp = new char*[sizeListOp];

        // Vamos guardando valores hasta encontrar un signo
            do
            {
                std::cout << "\n Entramos al do while. current[contCharOp] vale: " << currentOperation[contCharOp] << "\n";
                if(currentOperation[contCharOp] != 'x' && currentOperation[contCharOp] != '/' && currentOperation[contCharOp] != '-' && currentOperation[contCharOp] != '+')
                {
                    sizeListOp2++; // Contabilizamos cuántos valores se guardarán
                    std::cout << "\n SizeListOp2 vale: " << sizeListOp2 << "\n";
                }
                else
                {
                    // Guardamos los valores encontrados
                        std::cout << "\n Tocó un signo: " << currentOperation[contCharOp] << "\n";

                        std::cout << "\n La nueva sublista tendrá elementos: " << sizeListOp2 << "\n";

                        listOp[contListOp] = new char[sizeListOp2];

                        until = since + sizeListOp2;

                        std::cout << "\n desde: " << since << ", hasta: " << until << "\n";

                        for(short a = 0; since < until ; a++)
                        {
                            std::cout << "\n since=" << since << ", Guardamos " << currentOperation[since];

                            listOp[contListOp][a] = currentOperation[since]; // Guardamos
                            since++;
                        }
                    // Guardamos el signo
                        contListOp++;

                        std::cout << "\n Guardamos el signo en listaOp[" << contListOp << "][0] = " << currentOperation[since];

                        listOp[contListOp] = new char[1];
                        listOp[contListOp][0] = currentOperation[since];
                        since++;
                        contListOp++;

                    // Reiniciamos el valor de la sublista
                        sizeListOp2 = 0;
                }
                contCharOp++;

                std::cout << "\n LLegamos al final del d-while, contCharOp: " << contCharOp << ", sizeOp: " << sizeOp << "\n";

                // Verificamos si se llegó al final y guardamos lo último
                    if(contCharOp == sizeOp)
                    {
                        // Guardamos los valores encontrados
                            std::cout << "\n--- Se llegó al final" << contCharOp << "\n";

                            std::cout << "\n La nueva sublista tendrá elementos: " << sizeListOp2 << "\n";

                            listOp[contListOp] = new char[sizeListOp2];

                            until = since + sizeListOp2;

                            std::cout << "\n desde: " << since << ", hasta: " << until << "\n";

                            for(short a = 0; since < until ; a++)
                            {
                                std::cout << "\n since=" << since << ", Guardamos " << currentOperation[since];

                                listOp[contListOp][a] = currentOperation[since]; // Guardamos
                                since++;
                            }
                    }

            }while(contCharOp < sizeOp);

            std::cout << "\nSe guardó: \n";

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
