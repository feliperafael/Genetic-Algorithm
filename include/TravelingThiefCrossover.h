#ifndef TRAVELINGTHIEFCROSSOVER_H
#define TRAVELINGTHIEFCROSSOVER_H

#include "TravelingThiefIndividual.h"
#include "Crossover.h"

class TravelingThiefCrossover : Crossover
{
    public:
        TravelingThiefCrossover();
        void crossover(Individual* s1_, Individual* s2_);
        virtual ~TravelingThiefCrossover();

    protected:

    private:
};

#endif // TRAVELINGTHIEFCROSSOVER_H
