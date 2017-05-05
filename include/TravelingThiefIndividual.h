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
        vector<Item*>* knapsack;
        int amountOfCity;
        double weightKnapsack;
        double time;
        double distance;


        TravelingThiefIndividual(TravelingThiefDatabase * database);

        string nameIndividual(); // print name of individual
        Individual* clone();
        void print();
        virtual ~TravelingThiefIndividual();

        // functions for TravelingThiefIndividualBuilder
        void buildsRoute(TravelingThiefDatabase * database);
        void buildsRandomRoute(TravelingThiefDatabase * database);
        void buildsFartherFirstRoute(TravelingThiefDatabase * database);
        void buildKsnapsack();
        void smartBuildKsnapsack();
        void cleanKnapsack();
        bool knapsackAcceptsItem(Item * item);

        void addOnKnapsack(Item *item);

        void buildRouteOfLeastPath(TravelingThiefDatabase * database);

        double calculateDistance(City * a, City * b);


    protected:

    private:
        static bool sortItemsByCostWeight(Item* a, Item* b);
        static bool sortCitiesByDistanceCost(City* a, City* b);
        static bool sortCitiesByBiggerDistanceCost(City* a, City* b);

};

#endif // TRAVELINGTHIEFINDIVIDUAL_H
