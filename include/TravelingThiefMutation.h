#ifndef TRAVELINGTHIEFMUTATION_H
#define TRAVELINGTHIEFMUTATION_H

#include <vector>

#include "TravelingThiefIndividual.h"
#include "Mutation.h"

class TravelingThiefMutation : public Mutation
{
    public:
        TravelingThiefMutation();
        virtual void mutate(Individual * s);
        virtual ~TravelingThiefMutation();

    protected:

    private:
        void cityMutate(TravelingThiefIndividual * individual);
        void itemMutate(TravelingThiefIndividual * individual);
};

#endif // TRAVELINGTHIEFMUTATION_H
