#include "SimpleIndividualBuilder.h"

SimpleIndividualBuilder::SimpleIndividualBuilder()
{
    //ctor
}

Individual * SimpleIndividualBuilder::generateIndividuo(){
    return new SimpleIndividual();
}
string SimpleIndividualBuilder::nameIndividuo(){

}

SimpleIndividualBuilder::~SimpleIndividualBuilder()
{
    //dtor
}
