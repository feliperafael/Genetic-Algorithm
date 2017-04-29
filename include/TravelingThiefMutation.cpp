#include "TravelingThiefMutation.h"

TravelingThiefMutation::TravelingThiefMutation()
{
    //ctor
}

TravelingThiefMutation::~TravelingThiefMutation()
{
    //dtor
}

void TravelingThiefMutation::mutate(Individual * s){
    TravelingThiefIndividual * s1 = dynamic_cast<TravelingThiefIndividual*>(s);

    int cityA = 1 + rand() % (s1->amountOfCity - 1);
    int cityB = 1 + rand() % (s1->amountOfCity - 1);

//    cout << cityA << " " << cityB << endl;

    swap(s1->cities[cityA], s1->cities[cityB]);
    swap(s1->knapsack[cityA], s1->knapsack[cityB]);
}
