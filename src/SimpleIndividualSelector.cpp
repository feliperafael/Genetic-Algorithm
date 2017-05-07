#include "SimpleIndividualSelector.h"

SimpleIndividualSelector::SimpleIndividualSelector() {
    //ctor
}

Individual * SimpleIndividualSelector::selects(Individual ** pop) {
    Individual * x = pop[rand()%conf->popSize];
    Individual * y = pop[rand()%conf->popSize];

    if(x->fitness > y->fitness) {
        return x;
    }
    return y;

}

SimpleIndividualSelector::~SimpleIndividualSelector() {
    //dtor
}
