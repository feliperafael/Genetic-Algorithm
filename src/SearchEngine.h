#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "Configures.h"
#include "Individual.h"
#include "IndividuoBuilder.h"
#include "Parser.h"
#include "PopulationReplacement.h"
#include "Mutation.h"
#include "Crossover.h"

class SearchEngine
{
    public:
        Configures * conf;
        Individual ** population;
        IndividuoBuilder * individuoBuilder;
        Parser * parser;
        PopulationReplacement * replacer;
        Mutation * mutationOperator;
        Crossover * crossoverOperator;


        SearchEngine();

        void Operate();
        void Replace();
        void Evolve();
        virtual ~SearchEngine();

    protected:

    private:
        void EvaluatePopulation(int initialIndex, int finalIndex);
        static bool SortPopulationFitness(Individual* a, Individual* b);
        void createsInitialPopulation();
};

#endif // SEARCHENGINE_H
