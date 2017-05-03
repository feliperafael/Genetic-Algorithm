#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SearchEngine.h"
#include "Configures.h"

#include "SimpleParser.h"
#include "Database.h"
#include <omp.h>

#include "TravelingThiefDatabase.h"
#include "TravelingThiefIndividual.h"
#include "TravelingThiefIndividualBuilder.h"
#include "TravelingThiefParser.h"
#include "TravelingThiefMutation.h"
#include "TravelingThiefCrossover.h"
#include "TravelingThiefLocalSearch.h"


using namespace std;

int main(int argc, char * argv[])
{
    double wall_timer = omp_get_wtime();

    clock_t tick;
    tick = clock();
    int seed = atoi(argv[3]);

    if(atoi(argv[3]) == 0)
        seed = time(NULL);

    srand(seed);
    //srand(42);

    conf = new Configures(); //Configuration class with several GA parameters
    conf->seed = seed;
    conf->elitism = 0.2; // elitism percentage
    conf->generations = 10000; // num_max of generations
    conf->popSize = 500; // size of population
    conf->crossover = 0.5;  //crossing percentage
    conf->mutate = 1.0; // mutate percentage
    conf->MAX_THREADS = omp_get_max_threads(); // num_max_threads omp
    conf->max_generationsWithoutImprovement = 500;
    conf->MAX_TIME = atoi(argv[2]);


    //Create a problem database and load the input file.
    Database * database = new TravelingThiefDatabase();
    database->loadBase(argv[1]); // argv[1] is the path to the input file


    //Create an evaluator of the problem
    Parser * parser = new TravelingThiefParser();
    TravelingThiefParser * travelingthiefparser = dynamic_cast<TravelingThiefParser*>(parser);
    travelingthiefparser->setDatabase(database);


    //Define the individual generator that returns an individual type of problem specific
    TravelingThiefIndividualBuilder * travelingThiefIndividualBuilder = new TravelingThiefIndividualBuilder(database);

    SearchEngine * searcher = new SearchEngine();
    searcher->setParser(travelingthiefparser);
    searcher->setIndividualBuilder(travelingThiefIndividualBuilder);

    searcher->setMutation(new TravelingThiefMutation());

    TravelingThiefLocalSearch* ls = new TravelingThiefLocalSearch();
    ls->setParser(travelingthiefparser);

    searcher->setLocalSearch(ls);
    searcher->Evolve();

    cout << (omp_get_wtime() - wall_timer) << endl;

    return 0;
}
