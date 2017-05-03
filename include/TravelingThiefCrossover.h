#ifndef TRAVELINGTHIEFCROSSOVER_H
#define TRAVELINGTHIEFCROSSOVER_H

#include "TravelingThiefIndividual.h"
#include "Crossover.h"

class TravelingThiefCrossover : public Crossover
{
    public:
        TravelingThiefCrossover();
        void cross(Individual ** vec_individuos, int num_individuos);
        virtual ~TravelingThiefCrossover();

    protected:

    private:
};

#endif // TRAVELINGTHIEFCROSSOVER_H
