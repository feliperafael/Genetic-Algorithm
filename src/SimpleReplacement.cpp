#include "SimpleReplacement.h"

SimpleReplacement::SimpleReplacement() {
    //ctor
}

void SimpleReplacement::Replace(Individual **pop) {
    int elitismo = conf->elitism*conf->popSize;
    stable_sort(pop + elitismo, pop + conf->popSize * 2, SortMyPop);

    int indice;

    for(int i = elitismo; i < conf->popSize; i++) {
        indice = conf->popSize + i - elitismo;
        if(pop[i]->fitness < pop[indice]->fitness)
            swap(pop[i], pop[indice]);
    }
    stable_sort(pop, pop + conf->popSize * 2, SortMyPop);

}

bool SimpleReplacement::SortMyPop(Individual* a, Individual* b) {
    return a->fitness > b->fitness;
}


SimpleReplacement::~SimpleReplacement() {
    //dtor
}
