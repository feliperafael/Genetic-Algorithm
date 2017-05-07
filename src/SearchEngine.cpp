#include "SearchEngine.h"

SearchEngine::SearchEngine() {
    setParser(NULL);
    setPopulationReplace(NULL);
    setIndividualBuilder(NULL);
    setMutation(NULL);
    setCrossover(NULL);
    setSelection(NULL);
}

void SearchEngine::Evolve() {
    double time_init =  omp_get_wtime();
    createsInitialPopulation();

    //initial population evaluation. Mutation and crossing
    EvaluatePopulation(0, conf->popSize);
    stable_sort(population, population + conf->popSize, sortPopulationByFitness);


    double best;
    int generationsWithoutImprovement = 0;
    best = population[0]->fitness;


    doLocalSearch(0, conf->popSize);

    for(int it = 1; it < conf->generations; it++) {
        //Applies the genetic operators
        Operate();

        /**
            Note that the local search already evaluates a solution,
            not requiring an evaluation when a local search occurs
        **/
        ///Local Search
        if(it%conf->localSearchWindow == 0) {
            doLocalSearch(conf->popSize, conf->popSize * 2);
        } else {
            //Evaluates new population
            EvaluatePopulation(conf->popSize, conf->popSize * 2);
        }

        //Replaces the population
        replacer->Replace(population);

        // free temporary population
        for(int i = conf->popSize; i < conf->popSize * 2; ++i) {
            delete population[i];
        }


        if(best < population[0]->fitness) {
            best = population[0]->fitness;
            //cout << it << " " << best << endl;
            generationsWithoutImprovement=0;
        } else {
            generationsWithoutImprovement++;
        }

        //aumentar a variabilidade genetica
        if(generationsWithoutImprovement > conf->max_generationsWithoutImprovement){
            decimatePopulation();
            //cout << "Population was decimated" << endl;
            generationsWithoutImprovement=0;
           // break;
        }
        //cout << it << " " << population[0]->fitness <<  endl;
        if(omp_get_wtime() - time_init > conf->MAX_TIME)
            break;
    }

    //Prints the best result in n generations
    population[0]->print();

}

void SearchEngine::decimatePopulation(){
    for(int i = conf->elitism*conf->popSize; i < conf->popSize; i++){
        delete population[i];
        population[i] = individualBuilder->generateIndividuo();
        parser->Evaluate(population[i]);
    }
}

void SearchEngine::createsInitialPopulation() {
    //Creates the initial population
    population = new Individual*[conf->popSize * 2];

    for(int i = 0; i < conf->popSize; ++i) {
        population[i] = individualBuilder->generateIndividuo();
    }

}

void SearchEngine::EvaluatePopulation(int initialIndex, int finalIndex) {
    //cout << "EvaluatePopulation" << endl;
    #pragma omp parallel for num_threads(conf->MAX_THREADS)
    for(int i = initialIndex; i < finalIndex; ++i) {
//        cout << i << " - ";
//        cout << parser->nameParser() << endl;
        population[i]->fitness = parser->Evaluate(population[i]);
//        cout << population[i]->fitness << endl;
//        cin.get();
    }


}


void  SearchEngine::Operate() {
    Individual ** selecionados;
    int num_individuos = 2; // numero de individuos que vai ser selecionado
    for(int i = conf->popSize; i < conf->popSize * 2; i += num_individuos) {

        selecionados = new Individual*[num_individuos];

        for(int j = 0; j < num_individuos; j++) {
            selecionados[j] = individualSelector->selects(population)->clone();
            population[i+j] = selecionados[j];
        }
        //Applies crossover
        crossoverOperator->cross(selecionados,num_individuos);

        for(int j = 0; j < num_individuos; ++j) {
            //Applies mutation
            mutationOperator->mutate(selecionados[j]);
        }

        for(int j = 0; j < num_individuos; ++j) {
            selecionados[j] = NULL;
        }
        delete selecionados;
    }

}

void SearchEngine::doLocalSearch(int initialIndex, int finalIndex) {
    #pragma omp parallel for num_threads(conf->MAX_THREADS)
    for(int i = initialIndex; i < finalIndex; i++) {
        population[i] = localSearch->doLocalSearch(population[i]);
    }
}
bool SearchEngine::sortPopulationByFitness(Individual* a, Individual* b) {
    return a->fitness > b->fitness;
}

/**
   Set functions
**/

void SearchEngine::setIndividualBuilder(IndividualBuilder * indBuilder) {
    if(indBuilder == NULL) {
        this->individualBuilder = new SimpleIndividualBuilder();
    } else {
        this->individualBuilder = indBuilder;
    }
}

void SearchEngine::setMutation(Mutation * opMutation) {
    if(opMutation==NULL) {
        mutationOperator = new SimpleMutation();
    } else {
        mutationOperator = opMutation;
    }
}

void SearchEngine::setCrossover(Crossover * opCrossover) {
    if(opCrossover==NULL) {
        crossoverOperator = new SimpleCrossover();
    } else {
        crossoverOperator = opCrossover;
    }
}

void SearchEngine::setSelection(IndividualSelector * seletor) {
    if(seletor==NULL) {
        this->individualSelector = new SimpleIndividualSelector();
    } else {
        this->individualSelector = seletor;
    }
}

void SearchEngine::setParser(Parser * parser) {
    if(parser==NULL) {
        SimpleParser * avaliador  = new SimpleParser();
        // avaliador->setDataSet(database);
        this->parser = avaliador;
    } else {
        this->parser = parser;
    }
}

void SearchEngine::setPopulationReplace(PopulationReplacement * popReplace) {
    if(popReplace == NULL) {
        this->replacer = new SimpleReplacement();
    } else {
        this->replacer = popReplace;
    }
}

void SearchEngine::setLocalSearch(LocalSearch * localSearch) {
    this->localSearch = localSearch;
}

SearchEngine::~SearchEngine() {
    //dtor
}
