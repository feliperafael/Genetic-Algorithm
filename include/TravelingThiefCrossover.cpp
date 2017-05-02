#include "TravelingThiefCrossover.h"

TravelingThiefCrossover::TravelingThiefCrossover()
{
    //ctor
}

TravelingThiefCrossover::~TravelingThiefCrossover()
{
    //dtor
}

void TravelingThiefCrossover::cross(Individual** individuals, int size){
    TravelingThiefIndividual * s1 = dynamic_cast<TravelingThiefIndividual*>(individuals[0]);
    TravelingThiefIndividual * s2 = dynamic_cast<TravelingThiefIndividual*>(individuals[1]);

    int x = rand() % s1->amountOfCity;

    cout << "Partiu em " << x << endl;

    vector<City*> original1;
    vector<vector<Item*> > originalKnapsack1;
    vector<City*> original2;
    vector<vector<Item*> > originalKnapsack2;

    bool memory1[s1->amountOfCity] = {0};
    bool memory2[s1->amountOfCity] = {0};

    for(int i = 0; i < x; i++){
        original1.push_back(s1->cities[i]);
        originalKnapsack1.push_back(s1->knapsack[i]);
        memory1[s1->cities[i]->index] = 1;

        original2.push_back(s2->cities[i]);
        originalKnapsack2.push_back(s2->knapsack[i]);
        memory2[s2->cities[i]->index] = 1;
    }

    for(int i = x; i < s1->amountOfCity; i++){
        original1.push_back(s2->cities[i]);
        originalKnapsack1.push_back(s2->knapsack[i]);
        original2.push_back(s1->cities[i]);
        originalKnapsack2.push_back(s1->knapsack[i]);
    }

    for(int i = x; i < s1->amountOfCity; i++){
        if(memory1[original1[i]->index] == true){
            for(int j = 0; j < s1->amountOfCity; j++){
                if(memory1[s1->cities[j]->index] == false){
                    memory1[s1->cities[j]->index] = true;
                    original1[i] = s1->cities[j];
                    originalKnapsack1[i] = s1->knapsack[j];
                }
            }
        }

        if(memory2[original1[i]->index] == true){
            for(int j = 0; j < s2->amountOfCity; j++){
                if(memory2[s1->cities[j]->index] == false){
                    memory2[s1->cities[j]->index] = true;
                    original2[i] = s2->cities[j];
                    originalKnapsack2[i] = s2->knapsack[j];
                }
            }
        }
    }

    for(int i = x; i < s1->amountOfCity; i++){
        s1->cities[i] = original1[i];
        s1->knapsack[i] = originalKnapsack1[i];
        s2->cities[i] = original2[i];
        s2->knapsack[i] = originalKnapsack2[i];
    }

//    int s = rand() % s1->amountOfCity;
//    int e = rand() % s1->amountOfCity;
//
//    if(s > e)
//        swap(s, e);
//
//    /*** PMX ***/
//
//    vector<City*> original1;
//    vector<City*> original2;
//
//    for(int i = 0; i < s1->amountOfCity; i++){
//        original1.push_back(s1->cities[i]);
//        original2.push_back(s2->cities[i]);
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
//    for(int i = 0; i < s1->amountOfCity; i++){
//        if(memory1[s1->cities[i]->index] == true){
//            for(int j = 0; j < s1->amountOfCity; j++){
//                if(memory1[j] == false){
//                    memory1[j] = true;
////                    s1->cities[i]
//                }
//            }
//        }
//    }
}
