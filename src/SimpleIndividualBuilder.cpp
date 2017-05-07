#include "SimpleIndividualBuilder.h"

SimpleIndividualBuilder::SimpleIndividualBuilder() {
    //ctor
}

Individual * SimpleIndividualBuilder::generateIndividuo() {
    return new SimpleIndividual();
}
string SimpleIndividualBuilder::nameIndividuo() {
    return "SimpleIndividualBuilder";
}

SimpleIndividualBuilder::~SimpleIndividualBuilder() {
    //dtor
}
