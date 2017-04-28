#ifndef TRAVELINGTHIEFINDIVIDUAL_H
#define TRAVELINGTHIEFINDIVIDUAL_H

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <vector>
#include <algorithm>    // std::random_shuffle
#include "Individual.h"
#include "TravelingThiefDatabase.h"
#include "City.h"
#include "Item.h"


using namespace std;

class TravelingThiefIndividual : public Individual
{
    public:
        City ** cities;
        vector<Item*> knapsack;
        int amountOfCity;
        double weightKnapsack;


        TravelingThiefIndividual(TravelingThiefDatabase * database);

        string nameIndividual(); // print name of individual
        Individual* clone();
        void print();
        virtual ~TravelingThiefIndividual();

        // functions for TravelingThiefIndividualBuilder
        void buildsRoute(TravelingThiefDatabase * database);
        void buildsRandomRoute(TravelingThiefDatabase * database);
        void buildKsnapsack(TravelingThiefDatabase * database);
        bool knapsackAcceptsItem(Item * item);

        void addOnKnapsack(Item *item);

    protected:

    private:

};

#endif // TRAVELINGTHIEFINDIVIDUAL_H
