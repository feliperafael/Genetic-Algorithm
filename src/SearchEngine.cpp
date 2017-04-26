#include "SearchEngine.h"

SearchEngine::SearchEngine()
{
    //ctor
}

void SearchEngine::Evolve(){

    createsInitialPopulation();

    //initial population evaluation
    EvaluatePopulation(0, conf->popSize);

    for(int it = 1; it < conf->generations; it++){

        //Applies the genetic operators
        Operate();

        //Evaluates new population
        EvaluatePopulation(conf->popSize, conf->popSize * 2);

        //Replaces the population
        replacer->Replace(population);

        // free temporary population
        for(int i = conf->popSize; i < conf->popSize * 2; i++){
            delete population[i];
        }

    }

}

void SearchEngine::createsInitialPopulation(){


}

void SearchEngine::EvaluatePopulation(int initialIndex, int finalIndex){


}

void  SearchEngine::Operate(){


}

SearchEngine::~SearchEngine()
{
    //dtor
}
