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
        currentOperation = op;
    }
    void calc::setCurrentOperationSize(short sizeOp)
    {
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
        char** listOp;
        short contCharOp = 0, sizeListOp = 0, sizeListOp2 = 0, contSigns = 0;
        short contListOp = 0, since = 0, until = 0, sizeOp = getCurrentOperationSize();

        // verify how many symbols there is
            contSigns = countSymbols(currentOperation, sizeOp);

        // Put the sublist size
            sizeListOp = contSigns * 2 + 1;
            listOp = new char*[sizeListOp];

        // Store values until found a symbol
            do
            {
                if(currentOperation[contCharOp] != 'x' && currentOperation[contCharOp] != '/' && currentOperation[contCharOp] != '-' && currentOperation[contCharOp] != '+')
                {
                    sizeListOp2++; // Count how many valyes it will store
                }
                else
                {
                    // Store values founded
                        listOp[contListOp] = new char[sizeListOp2];
                        until = since + sizeListOp2;

                        listOp[contListOp] = storeValues(currentOperation, until, &since, sizeListOp2);

                    // Store the symbol
                        contListOp++;
                        listOp[contListOp] = new char[1];
                        listOp[contListOp][0] = currentOperation[since];
                        since++;
                        contListOp++;

        // Restart the sublist size
            sizeListOp2 = 0;
                }
                contCharOp++;

                // Verify if is the end
                    if(contCharOp == sizeOp)
                    {
                        // Sore values founded
                            listOp[contListOp] = new char[sizeListOp2];
                            until = since + sizeListOp2;

                            for(short a = 0; since < until ; a++)
                            {
                                listOp[contListOp][a] = currentOperation[since]; // Store
                                since++;
                            }
                    }
            }while(contCharOp < sizeOp);

            std::cout << "\nSe guardó:\n";

            for(short a = 0; a < sizeListOp; a++)
                std::cout << "-listOp[" << a << "]: " << listOp[a] << "\n";

            return true;
    }
    short calc::countSymbols(char op[], short sizeOp)
    {
        short contSigns = 0;
        for(int a = 0; a < sizeOp; a++)
            if(op[a] == '+' || op[a] == '-' || op[a] == 'x' || op[a] == '/')
                contSigns++;
        return contSigns;
    }
    char* calc::storeValues(char op[], short until, short *since, short sizeListOp2)
    {
        std::cout << "\nEstamos en storeValues, since: " << *since << ", until: " << until << ", sizelistOp2: " << sizeListOp2 << "\n";

        char* listOp;
        listOp = new char[sizeListOp2];
        // Store values founded
            for(short a = 0; *since < until ; a++)
            {
                std::cout << "Guardamos listOp[" << a << "]: " << op[*since] << "\n";
                std::cout << "since: " << *since << ", until: " << until << "\n";

                listOp[a] = op[*since]; // Store
                *since = *since + 1;
            }
            std::cout << "\n Retornamos: " << listOp << "\n";
        return listOp;
    }
