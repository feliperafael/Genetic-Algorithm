#include "TravelingThiefIndividualBuilder.h"

TravelingThiefIndividualBuilder::TravelingThiefIndividualBuilder(Database * database)
{
    this->database = dynamic_cast<TravelingThiefDatabase*>(database);

    this->database->print();

}


Individual * TravelingThiefIndividualBuilder::generateIndividuo(){
    TravelingThiefIndividual * i = new TravelingThiefIndividual(database);
    if(rand()%2 == 0)
        i->buildsRoute(database);
    else
        i->buildRouteOfLeastPath(database);
    return i;
}


string TravelingThiefIndividualBuilder::nameIndividuo(){
    return "TravelingThiefIndividualBuilder";
}

TravelingThiefIndividualBuilder::~TravelingThiefIndividualBuilder()
{

}
