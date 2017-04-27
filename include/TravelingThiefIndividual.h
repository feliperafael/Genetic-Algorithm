#ifndef TRAVELINGTHIEFINDIVIDUAL_H
#define TRAVELINGTHIEFINDIVIDUAL_H

#include "Individual.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

class TravelingThiefIndividual : public Individual
{
    public:
        int **cityBackpack;
        TravelingThiefIndividual();


        string nameIndividual(); // print name of individual
        Individual* clone();
        void print();
        virtual ~TravelingThiefIndividual();

    protected:

    private:
};

#endif // TRAVELINGTHIEFINDIVIDUAL_H
