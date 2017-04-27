#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SearchEngine.h"
#include "Configures.h"

#include "SimpleParser.h"
#include "Database.h"
#include <omp.h>

#include "TravelingThiefDatabase.h"
using namespace std;

int main(int argc, char * argv[])
{
    srand(time(NULL));
    Database * database = new TravelingThiefDatabase();
    database->loadBase(argv[1]);

    Parser * parser = new SimpleParser();
    SimpleParser * simpleParser = dynamic_cast<SimpleParser*>(parser);
    simpleParser->setDatabase(database);


    conf = new Configures(); //Configuration class with several GA parameters
    conf->elitism = 0.1;
    conf->generations = 100;
    conf->popSize = 2000;
    conf->crossover = 0.5;
    conf->MAX_T = omp_get_max_threads();

    SearchEngine * searcher = new SearchEngine();
    searcher->setParser(simpleParser);

    searcher->Evolve();

    return 0;
}
