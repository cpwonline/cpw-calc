#ifndef CALC_H
#define CALC_H


class calc
{
    public:
        calc();
        virtual ~calc();
        float sum(float a, float b);
        float rest(float a, float b);
        float multiplicate(float a, float b);
        float divide(float a, float b);
        bool error;

    protected:

    private:
        float result, operations;
};

#endif // CALC_H
