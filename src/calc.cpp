#include "calc.h"

calc::calc()
{
    setResult(0.00);
    setBuffer(0.00);
    error = false;
}

float calc::getResult()
{
    return this->result;
}
float calc::getBuffer()
{
    return this->buffer;
}
float calc::getHistorial()
{
    return this->historial;
}

void calc::setResult(float r)
{
    this->result = r;
}
void calc::setBuffer(float b)
{
    this->buffer = b;
}
void calc::setHistorial(float h)
{
    this->historial = h;
}

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
