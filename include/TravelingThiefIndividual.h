#ifndef TRAVELINGTHIEFINDIVIDUAL_H
#define TRAVELINGTHIEFINDIVIDUAL_H

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include "Individual.h"
#include "City.h"
#include "Item.h"


using namespace std;

class TravelingThiefIndividual : public Individual
{
    public:
        vector<City*> cities;
        vector<Item*> items;
        TravelingThiefIndividual();


        string nameIndividual(); // print name of individual
        Individual* clone();
        void print();
        virtual ~TravelingThiefIndividual();

    protected:

    private:
};

#endif // TRAVELINGTHIEFINDIVIDUAL_H
