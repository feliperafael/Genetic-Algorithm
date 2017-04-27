#ifndef TRAVELINGTHIEFBUILDERINDIVIDUAL_H
#define TRAVELINGTHIEFBUILDERINDIVIDUAL_H
#include "IndividualBuilder.h"

class TravelingThiefIndividualBuilder : public IndividualBuilder
{
    public:
        TravelingThiefIndividualBuilder();

        Individual * generateIndividuo();
        string nameIndividuo();

        virtual ~TravelingThiefIndividualBuilder();

    protected:

    private:
};

#endif // TRAVELINGTHIEFBUILDERINDIVIDUAL_H
