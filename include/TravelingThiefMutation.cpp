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
    if(rand()%100 < conf->mutate*100){
        cityMutate(s1);
    }

}

void TravelingThiefMutation::cityMutate(TravelingThiefIndividual * individual){
    int cityA = 1 + rand() % (individual->amountOfCity - 1);
    int cityB = 1 + rand() % (individual->amountOfCity - 1);

    swap(individual->cities[cityA], individual->cities[cityB]);
    swap(individual->knapsack[cityA], individual->knapsack[cityB]);

    individual->cleanKnapsack();
    //cout << "PESO : "<< individual->weightKnapsack << " FIT " << individual->fitness << endl;
    if(rand()%2==0)
        individual->smartBuildKsnapsack();
    else
        individual->buildKsnapsack();
   // cout << "PESO : "<< individual->weightKnapsack << " FIT " << individual->fitness << endl;cin.get();
}


void TravelingThiefMutation::itemMutate(TravelingThiefIndividual * individual){


}
