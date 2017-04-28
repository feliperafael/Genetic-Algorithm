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
using namespace std;

int main(int argc, char * argv[])
{
    srand(time(NULL));

    conf = new Configures(); //Configuration class with several GA parameters
    conf->elitism = 0.1; // elitism percentage
    conf->generations = 1000; // num_max of generations
    conf->popSize = 10; // size of population
    conf->crossover = 0.5;  //crossing percentage
    conf->MAX_THREADS = omp_get_max_threads(); // num_max_threads omp


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


    searcher->Evolve();



    return 0;
}
