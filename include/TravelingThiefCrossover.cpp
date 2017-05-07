#include "TravelingThiefCrossover.h"

TravelingThiefCrossover::TravelingThiefCrossover() {
    //ctor
}

TravelingThiefCrossover::~TravelingThiefCrossover() {
    //dtor
}

void TravelingThiefCrossover::cross(Individual** individuals, int size) {
    TravelingThiefIndividual * s1 = dynamic_cast<TravelingThiefIndividual*>(individuals[0]);
    TravelingThiefIndividual * s2 = dynamic_cast<TravelingThiefIndividual*>(individuals[1]);

    int x = rand() % s1->amountOfCity;


    vector<City*> original1;

    vector<City*> original2;


    bool memory1[s1->amountOfCity] = {0};
    bool memory2[s1->amountOfCity] = {0};

    for(int i = 0; i < x; i++) {
        original1.push_back(s1->cities[i]);

        memory1[s1->cities[i]->index] = 1;

        original2.push_back(s2->cities[i]);

        memory2[s2->cities[i]->index] = 1;
    }

    for(int i = x; i < s1->amountOfCity; i++) {
        original1.push_back(s2->cities[i]);

        original2.push_back(s1->cities[i]);

    }

    for(int i = x; i < s1->amountOfCity; i++) {
        if(memory1[original1[i]->index] == true) {
            for(int j = 0; j < s1->amountOfCity; j++) {
                if(memory1[s1->cities[j]->index] == false) {
                    memory1[s1->cities[j]->index] = true;
                    original1[i] = s1->cities[j];

                }
            }
        }

        if(memory2[original1[i]->index] == true) {
            for(int j = 0; j < s2->amountOfCity; j++) {
                if(memory2[s1->cities[j]->index] == false) {
                    memory2[s1->cities[j]->index] = true;
                    original2[i] = s2->cities[j];

                }
            }
        }
    }

    for(int i = x; i < s1->amountOfCity; i++) {
        s1->cities[i] = original1[i];

        s2->cities[i] = original2[i];

    }

    original1.clear();
    original2.clear();
}
