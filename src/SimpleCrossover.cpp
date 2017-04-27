#include "SimpleCrossover.h"

SimpleCrossover::SimpleCrossover()
{
    //ctor
}

void SimpleCrossover::cross(Individual ** vec_individuos, int num_individuos){

    for(int i = 1; i < num_individuos; i+=2){
        SimpleIndividual * s1 = dynamic_cast<SimpleIndividual*>(vec_individuos[i-1]);
        SimpleIndividual * s2 = dynamic_cast<SimpleIndividual*>(vec_individuos[i]);
        if(rand()%100 < conf->crossover*100){
            s1->x = (s1->x + s2->x)/2;
            s2->x = (s1->x + s2->x)/2;
        }
    }


}

SimpleCrossover::~SimpleCrossover()
{
    //dtor
}
