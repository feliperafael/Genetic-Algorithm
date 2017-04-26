#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "Individual.h"
#include "IndividuoBuilder.h"
#include "Parser.h"
#include "PopulationReplacement.h"
#include "Mutation.h"
#include "Crossover.h"

class SearchEngine
{
    public:
        Individual ** population;
        IndividuoBuilder * individuoBuilder;
        Parser * parser;
        PopulationReplacement * replacer;
        Mutation * mutationOperator;
        Crossover * crossoverOperator;


        SearchEngine();
        virtual ~SearchEngine();

    protected:

    private:
        void EvaluatePopulation(int initialIndex, int finalIndex);
        static bool SortPopulationFitness(Individual* a, Individual* b);
        void createsInitialPopulation();
};

#endif // SEARCHENGINE_H
