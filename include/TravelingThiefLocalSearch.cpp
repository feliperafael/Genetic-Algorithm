#include "TravelingThiefLocalSearch.h"

TravelingThiefLocalSearch::TravelingThiefLocalSearch() {

}

TravelingThiefIndividual* TravelingThiefLocalSearch::doLocalSearch(Individual* s1) {
    TravelingThiefIndividual * individual;

    ///Has a 50% chance to perform the local search on the route or 50% chance to search the ksnapsack
    if(rand()%2==0)
        individual = TwoOpt(dynamic_cast<TravelingThiefIndividual*>(s1));
    else
        individual =  knapsackLocalSearch(dynamic_cast<TravelingThiefIndividual*>(s1));
    return individual;
}

TravelingThiefIndividual* TravelingThiefLocalSearch::TwoOpt(TravelingThiefIndividual* s1) {
    // Get tour size
    int size = s1->amountOfCity;

    // repeat until no improvement is made
    int improve = 0;
    int iterations = 0;

    TravelingThiefIndividual* s2;

    while (improve < 1 && ++iterations < 5) {
        double best_distance = s1->distance;

        for(int i = 0; i < size - 1; i++) {
            for(int k = i + 1; k < size; k++) {
                s2 = dynamic_cast<TravelingThiefIndividual*>(s1->clone());
                TwoOptSwap(s1, s2, i, k);
//                s2->print();
                double new_distance = s2->distance;

                if(new_distance < best_distance) {
//                     Improvement found so reset
                    improve++;
                    swap(s1, s2);
                    best_distance = new_distance;
                }
                delete s2;
            }
        }
    }

    return s1;
}

void TravelingThiefLocalSearch::TwoOptSwap(TravelingThiefIndividual* s1, TravelingThiefIndividual* s2, const int& i, const int& k) {
    int size = s1->amountOfCity;

    // 1. take route[0] to route[i-1] and add them in order to new_route
    for(int c = 0; c <= i - 1; ++c) {
        s2->cities[c] = s1->cities[c];
    }

    // 2. take route[i] to route[k] and add them in reverse order to new_route
    int dec = 0;
    for(int c = i; c <= k; ++c) {
        s2->cities[c] = s1->cities[k - dec];
        dec++;
    }

    // 3. take route[k+1] to end and add them in order to new_route
    for(int c = k + 1; c < size; ++c) {
        s2->cities[c] = s1->cities[c];
    }

    parser->Evaluate(s2);
}

void TravelingThiefLocalSearch::setDatabase(TravelingThiefDatabase * database) {
    this->database = database;
}
/***
    @parameters TravelingThiefIndividual* s
    @return TravelingThiefIndividual *

    Given a wheel and a backpack. Generate SIZE random backpacks
    for a given route and return the best one or the original if
    it does not get better.
**/
TravelingThiefIndividual * TravelingThiefLocalSearch::knapsackLocalSearch(TravelingThiefIndividual* s) {

    int SIZE = database->DIMENSION*3;
    TravelingThiefIndividual * pop[SIZE];
    int amountOfCity = database->DIMENSION;

    for(int i = 0 ; i < SIZE; i++) {
        pop[i] = dynamic_cast<TravelingThiefIndividual*>(s->clone());

        for(int j = 0; j < amountOfCity; j++) {
            if(pop[i]->knapsack[j].size() > 0) {
                int sizeKnapsack = pop[i]->knapsack[j].size();

                for(int k =0; k < sizeKnapsack; k++) {
                    if(rand()%3==0) {
                        pop[i]->removeOnKnapsack(j,k);
                    }
                }
            } else { //não pegou o item daquela cidadde
                if(rand()%2==0) {

                    bool alreadyExists;
                    for(Item * item : database->cities[j]->items) {
                        alreadyExists = false;
                        for(Item * item_knap : s->knapsack[j]) {
                            if(item_knap->index == item->index) {
                                alreadyExists = true;
                            }
                        }
                        if(!alreadyExists) {
                            if(pop[i]->knapsackAcceptsItem(item)) {
                                pop[i]->addOnKnapsack(item);
                            }
                        }

                    }
                }
            }
        }

    }
    //Evaluete new knapsacks
    for(int i = 0 ; i < SIZE; ++i) {
        parser->Evaluate(pop[i]);
    }

    stable_sort(pop, pop + SIZE, sortPopulationByFitness);


    for(int i = 1; i < SIZE; ++i) {
        delete pop[i];
    }
    if(pop[0]->fitness > s->fitness) {
        return pop[0];
    }
    delete pop[0];
    return s;

}

bool TravelingThiefLocalSearch::sortPopulationByFitness(Individual* a, Individual* b) {
    return a->fitness > b->fitness;
}

TravelingThiefLocalSearch::~TravelingThiefLocalSearch() {
    //dtor
}
