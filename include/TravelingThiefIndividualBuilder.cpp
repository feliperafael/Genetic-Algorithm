#include "TravelingThiefIndividualBuilder.h"

TravelingThiefIndividualBuilder::TravelingThiefIndividualBuilder(Database * database)
{
    this->database = dynamic_cast<TravelingThiefDatabase*>(database);

    this->database->print();
    //ctor
}


Individual * TravelingThiefIndividualBuilder::generateIndividuo(){
    TravelingThiefIndividual * i = new TravelingThiefIndividual(database);
//    i->buildsRoute(database);
    return i;
}


string TravelingThiefIndividualBuilder::nameIndividuo(){
    return "TravelingThiefIndividualBuilder";
}

TravelingThiefIndividualBuilder::~TravelingThiefIndividualBuilder()
{
    //dtor
}
