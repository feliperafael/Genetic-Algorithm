#include "SearchEngine.h"

SearchEngine::SearchEngine()
{
    //ctor
}

void SearchEngine::Evolve()
{

    createsInitialPopulation();

    //initial population evaluation
    EvaluatePopulation(0, conf->popSize);

    for(int it = 1; it < conf->generations; it++)
    {

        //Applies the genetic operators
        Operate();

        //Evaluates new population
        EvaluatePopulation(conf->popSize, conf->popSize * 2);

        //Replaces the population
        replacer->Replace(population);

        // free temporary population
        for(int i = conf->popSize; i < conf->popSize * 2; i++)
        {
            delete population[i];// passar para dentro do replace?
        }

    }

}

void SearchEngine::createsInitialPopulation()
{
    //Creates the initial population


}

void SearchEngine::EvaluatePopulation(int initialIndex, int finalIndex)
{

    for(int i = initialIndex; i < finalIndex; i++){
        population[i]->fitness = parser->Evaluate(population[i]);
    }
}

void  SearchEngine::Operate()
{
    Individual ** selecionados;
    int num_individuos = 2; // numero de individuos que vai ser selecionado
    for(int i = conf->popSize; i < conf->popSize * 2; i += num_individuos)
    {

        selecionados = new Individual*[num_individuos];

        for(int j = 0; j < num_individuos; j++)
        {
            selecionados[j] = individualSelector->selects(population)->clone();
            population[i+j] = selecionados[j];
        }
        //Applies crossover
        crossoverOperator->cross(selecionados,num_individuos);

        for(int j = 0; j < num_individuos; j++)
        {
            //Applies mutation
            mutationOperator->mutate(selecionados[j]);
        }

        for(int j = 0; j < num_individuos; j++)
        {
            selecionados[j] = NULL;
        }
        delete selecionados;
    }

}

 bool SearchEngine::SortPopulationByFitness(Individual* a, Individual* b){
    return a->fitness < b->fitness;
 }

 /***/

 void SearchEngine::setIndividualBuilder(IndividualBuilder * indBuilder){
    if(indBuilder == NULL){
        this->individualBuilder = new SimpleIndividualBuilder();
    }else{
        this->individualBuilder = indBuilder;
    }
}

void SearchEngine::setMutation(Mutation * opMutation){
    if(opMutation==NULL){
        mutationOperator = new SimpleMutation();
    }else{
        mutationOperator = opMutation;
    }
}

void SearchEngine::setCrossover(Crossover * opCrossover){
    if(opCrossover==NULL){
        crossoverOperator = new SimpleCrossover();
    }else{
        crossoverOperator = opCrossover;
    }
}

void SearchEngine::setSelection(IndividualSelector * seletor){
    if(seletor==NULL){
        this->individualSelector = new SimpleIndividualSelector();
    }else{
        this->individualSelector = seletor;
    }
}

SearchEngine::~SearchEngine()
{
    //dtor
}
