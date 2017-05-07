#include "SimpleIndividual.h"

SimpleIndividual::SimpleIndividual() {

    //ctor
    this->x = double(rand());
    if(rand()%2==0) {
        x *= -1;
    }

}

string SimpleIndividual::nameIndividual() {
    return "SimpleIndividual";
} // print name of individual

Individual* SimpleIndividual::clone() {
    SimpleIndividual * s = new SimpleIndividual();
    s->fitness = fitness;
    s->x = x;
    return s;
}

void SimpleIndividual::print() {
    cout << "fitness(" << x << ") = " << fitness << endl;
}

SimpleIndividual::~SimpleIndividual() {
    //dtor
}
