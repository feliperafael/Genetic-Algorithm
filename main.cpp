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
   // double wall_timer = omp_get_wtime();

    clock_t tick;
    tick = clock();
    int seed = atoi(argv[3]);

    if(atoi(argv[3]) == 0)
        seed = time(NULL);

    srand(seed);
    //srand(42);

    conf = new Configures(); //Configuration class with several GA parameters
    conf->elitism = 0.2; // elitism percentage
    conf->generations = 10000; // num_max of generations
    conf->popSize = 10000; // size of population
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
////    searcher->setCrossover(new TravelingThiefCrossover());

//    TravelingThiefCrossover* crossover = new TravelingThiefCrossover();
//
//    Individual* s[2];
//
//    s[0] = travelingThiefIndividualBuilder->generateIndividuo();
//    s[1] = travelingThiefIndividualBuilder->generateIndividuo();
//
//    s[0]->print();
//    s[1]->print();
//
//    crossover->cross(s, 2);
//
//    s[0]->print();
//    s[1]->print();

    TravelingThiefIndividual* s = dynamic_cast<TravelingThiefIndividual*>(travelingThiefIndividualBuilder->generateIndividuo());
    travelingthiefparser->Evaluate(s);

    TravelingThiefLocalSearch* ls = new TravelingThiefLocalSearch();
    ls->setParser(travelingthiefparser);
    s->print();
    s = ls->doLocalSearch(s);
    s->print();

//    searcher->Evolve();


   // cout << "\ntime : " <<  (omp_get_wtime() - wall_timer) << " s" << endl;
    cout << "seed " << seed << endl;
    cout << "MAX TIME :" << conf->MAX_TIME << endl;




    return 0;
}
