#include "TravelingThiefIndividualBuilder.h"

TravelingThiefIndividualBuilder::TravelingThiefIndividualBuilder(Database * database)
{
    this->database = dynamic_cast<TravelingThiefDatabase*>(database);

    this->database->print();

}


Individual * TravelingThiefIndividualBuilder::generateIndividuo(){
    TravelingThiefIndividual * i = new TravelingThiefIndividual(database);
    int randomNum = rand();
    if(randomNum%3 == 0){
        i->buildsRoute(database);
    }else if(randomNum%3 == 1)
        i->buildRouteOfLeastPath(database);
    else
        i->buildsFartherFirstRoute(database);
    return i;
}


string TravelingThiefIndividualBuilder::nameIndividuo(){
    return "TravelingThiefIndividualBuilder";
}

TravelingThiefIndividualBuilder::~TravelingThiefIndividualBuilder()
{

}
