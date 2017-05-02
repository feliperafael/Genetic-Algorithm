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


using namespace std;

int main(int argc, char * argv[])
{
    clock_t tick;
    tick = omp_get_wtime();
    int seed = time(NULL);

    srand(seed);
    cout << "seed " << seed << endl;
    //srand(42);

    conf = new Configures(); //Configuration class with several GA parameters
    conf->elitism = 0.2; // elitism percentage
    conf->generations = 10000; // num_max of generations
    conf->popSize = 10000; // size of population
    conf->crossover = 0.5;  //crossing percentage
    conf->mutate = 1.0; // mutate percentage
    conf->MAX_THREADS = omp_get_max_threads(); // num_max_threads omp
    conf->max_generationsWithoutImprovement = 500;


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

    searcher->Evolve();


    double Tempo = (omp_get_wtime() - tick);
    printf("Tempo gasto: %g. s", Tempo);




    return 0;
}
