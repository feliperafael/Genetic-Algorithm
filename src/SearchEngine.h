#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H
#include <omp.h>
#include "Configures.h"
#include "Individual.h"
#include "IndividualBuilder.h"
#include "IndividualSelector.h"
#include "Parser.h"
#include "PopulationReplacement.h"
#include "Mutation.h"
#include "Crossover.h"
#include "SimpleIndividual.h"
#include "SimpleIndividualBuilder.h"
#include "SimpleMutation.h"
#include "SimpleCrossover.h"
#include "SimpleIndividualSelector.h"
#include "SimpleParser.h"
#include "SimpleReplacement.h"

class SearchEngine
{
    public:
        Individual ** population;
        IndividualBuilder * individualBuilder;
        Parser * parser;
        PopulationReplacement * replacer;
        Mutation * mutationOperator;
        Crossover * crossoverOperator;
        IndividualSelector * individualSelector;


        SearchEngine();

        void Operate();
        void Replace();
        void Evolve();
        virtual ~SearchEngine();

        void setCrossover(Crossover * opCrossover);
        void setMutation(Mutation * opMutation);
        void setIndividualBuilder(IndividualBuilder * indBuilder);
        void setPopulationReplace(PopulationReplacement * popReplace);
        void setParser(Parser * parser);
        void setSelection(IndividualSelector * seletor);

    protected:

    private:
        void EvaluatePopulation(int initialIndex, int finalIndex);
        static bool SortPopulationByFitness(Individual* a, Individual* b);
        void createsInitialPopulation();
};

#endif // SEARCHENGINE_H
