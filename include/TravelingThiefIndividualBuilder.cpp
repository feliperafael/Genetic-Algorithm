#include "TravelingThiefIndividualBuilder.h"

TravelingThiefIndividualBuilder::TravelingThiefIndividualBuilder(Database * database) {
    this->database = dynamic_cast<TravelingThiefDatabase*>(database);

    this->database->print();

}


Individual * TravelingThiefIndividualBuilder::generateIndividuo() {
    TravelingThiefIndividual * i = new TravelingThiefIndividual(database);
    int randomNum = rand()%100;
    if(randomNum < 50) {
        i->buildsRoute(database);
    } else if(randomNum < 90)
        i->buildRouteOfLeastPath(database);
    else
        i->buildsFartherFirstRoute(database);
//    i->print();
//    cin.get();
    return i;
}


string TravelingThiefIndividualBuilder::nameIndividuo() {
    return "TravelingThiefIndividualBuilder";
}

TravelingThiefIndividualBuilder::~TravelingThiefIndividualBuilder() {

}
