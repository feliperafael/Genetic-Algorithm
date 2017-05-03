#ifndef TRAVELINGTHIEFLOCALSEARCH_H
#define TRAVELINGTHIEFLOCALSEARCH_H

#include "LocalSearch.h"
#include "TravelingThiefIndividual.h"

class TravelingThiefLocalSearch : public LocalSearch
{
    public:
        TravelingThiefLocalSearch();
        void doLocalSearch(Individual* s1);
        virtual ~TravelingThiefLocalSearch();

        void TwoOpt(TravelingThiefIndividual * s1_);
        void TwoOptSwap(TravelingThiefIndividual* s1, TravelingThiefIndividual* s2, const int& i, const int& k);

    protected:

    private:
};

#endif // TRAVELINGTHIEFLOCALSEARCH_H
