#ifndef SIMPLEINDIVIDUAL_H
#define SIMPLEINDIVIDUAL_H
#include "Individual.h"

class SimpleIndividual : public Individual
{
    public:
        int * vec;
        SimpleIndividual();

        virtual string nameIndividual(); // print name of individual
        virtual Individual* clone();
        virtual void print();

        virtual ~SimpleIndividual();

    protected:

    private:
};

#endif // SIMPLEINDIVIDUAL_H
