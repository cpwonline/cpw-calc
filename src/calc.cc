#include "calc.h"
#include <iostream>
#include <cstdlib>

// Constructor and destructor
    calc::calc()
    {
        setResult(0.00);
        setBuffer(0.00);
        setHistorial(0.00);
        error = false;
    }
    calc::~calc()
    {
		
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
    std::vector<char> calc::getCurrentOperation() const
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
        for(int a = 0; a < sizeChar; a++) currentOperation.push_back(op[a]); 
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
        short contListOp = 0, since = 0, until = 0, sizeOp = currentOperation.size();

        // verify how many symbols there is
            contSigns = countSymbols();

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
                        listOp[contListOp] = (char*)std::malloc[sizeListOp2];

                        listOp[contListOp] = storeValues(&since, sizeListOp2);

                    // Store the symbol
                        contListOp++;
                        listOp[contListOp] = (char*)std::malloc(1);

                        listOp[contListOp] = storeValues(&since, 1);

                        contListOp++;

                    // Restart the sublist size
                        sizeListOp2 = 0;
                }
                contCharOp++;

                // Verify if is the end
                    if(contCharOp == sizeOp)
                    {
                        // Sore values founded
                            listOp[contListOp] = (char*)std::malloc[sizeListOp2];

                            listOp[contListOp] = storeValues(&since, sizeListOp2);
                    }
            }while(contCharOp < sizeOp);

            std::cout << "\nSe guardó:\n";

            for(short a = 0; a < sizeListOp; a++)
                std::cout << "-listOp[" << a << "]: " << listOp[a] << "\n";

			std::cout << "\n* Pasando a los nuevos arrays--\n";
		/*
			char** listOp2;
			bool end = false;
			int a = 0;
			do
			{
				short majObj = objPreGen.sizeArith;
				if(listOp[a] == objPreGen.arithmeticOp[majObj])
				{
					double val1 = (double) listOp[a - 1];
					double val2 = (double) listOp[a + 1];
					double result;
					
					switch(objPreGen.arithmeticOp[majObj])
					{
						case '/':
							result = val1 / val2;
							break;
					}

					delete[] listOp[a - 1];
					listOp[a - 1] = new char[3];
					listOp[a - 1] = "NOT";
					delete[] listOp[a + 1];
					listOp[a + 1] = new char[3];
					listOp[a + 1] = "NOT";
					delete[] listOp[a];
					listOp[a] = new double(result);

					end = true;
				}
				a++;
			}while(!end);
			
            std::cout << "\nSe guardó:\n";

            for(short a = 0; a < sizeListOp; a++)
                std::cout << "-listOp[" << a << "]: " << listOp[a] << "\n";

			std::cout << "\n* Pasando a los nuevos arrays--\n";
*/
            for(short a = 0; a < sizeListOp; a++) std::free(listOp[a]);
			
			delete[] listOp;
	
            return true;
    }
    short calc::countSymbols()
    {
        short contSigns = 0;
        for(int a = 0; a < currentOperation.size(); a++)
            if(currentOperation[a] == '+' || currentOperation[a] == '-' || currentOperation[a] == 'x' || currentOperation[a] == '/')
                contSigns++;
        return contSigns;
    }
    char* calc::storeValues(short *since, short sizeListOp2)
    {
        short until = *since + sizeListOp2;
        char* listOp;
        listOp = new char[sizeListOp2];
        // Store values founded
            for(short a = 0; *since < until ; a++)
            {
                listOp[a] = currentOperation[*since]; // Store
                *since = *since + 1;
            }

        return listOp;
    }
