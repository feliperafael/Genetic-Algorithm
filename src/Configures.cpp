#include "Configures.h"

Configures::Configures() {
    //ctor
    max_generationsWithoutImprovement = 50;
    MAX_TIME = 0;
    localSearchWindow = 5;
}

Configures::~Configures() {
    //dtor
}

Configures * conf;
