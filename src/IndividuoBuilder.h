#ifndef INDIVIDUOBUILDER_H
#define INDIVIDUOBUILDER_H
#include "Individual.h"

class IndividuoBuilder
{
    public:
        IndividuoBuilder();
        virtual ~IndividuoBuilder();
        virtual Individual * generateIndividuo() = 0;
        virtual string nameIndividuo() = 0;

    protected:

    private:
};

#endif // INDIVIDUOBUILDER_H
