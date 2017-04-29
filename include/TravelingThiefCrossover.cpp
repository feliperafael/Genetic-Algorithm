#include "TravelingThiefCrossover.h"

TravelingThiefCrossover::TravelingThiefCrossover()
{
    //ctor
}

TravelingThiefCrossover::~TravelingThiefCrossover()
{
    //dtor
}

void TravelingThiefCrossover::crossover(Individual * s1_, Individual* s2_){
//    TravelingThiefIndividual * s1 = dynamic_cast<TravelingThiefIndividual*>(s1_);
//    TravelingThiefIndividual * s2 = dynamic_cast<TravelingThiefIndividual*>(s2_);
//
//    int s = rand() % s1->amountOfCity;
//    int e = rand() % s1->amountOfCity;
//
//    if(s > e)
//        swap(s, e);
//
//    /*** PMX ***/
//
//    int original1[s1->amountOfCity];
//    int original2[s1->amountOfCity];
//
//    for(int i = 0; i < s1->amountOfCity; i++){
//        original1[i] = s1->cities[i]->index;
//        original2[i] = s2->cities[i]->index;
//    }
//
//    bool memory1[s1->amountOfCity] = {0};
//    bool memory2[s1->amountOfCity] = {0};
//
//    for(int i = s; i <= e; i++){
//        memory1[s2->cities[i]->index] = 1;
//        memory2[s1->cities[i]->index] = 1;
//
//        swap(s1->cities[i], s2->cities[i]);
//        swap(s1->knapsack[i], s2->knapsack[i]);
//    }
//
////    fixing s1
//    for(int i = 0; i < s1->amountOfCity; i++){
//        if(i < s || i > e){
//            if(memory1[original1[i]]){
//                int pos = find()
//            }
//        }
//    }
}
