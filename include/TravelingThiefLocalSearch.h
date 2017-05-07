#ifndef TRAVELINGTHIEFLOCALSEARCH_H
#define TRAVELINGTHIEFLOCALSEARCH_H

#include "LocalSearch.h"
#include "TravelingThiefIndividual.h"
#include "TravelingThiefDatabase.h"

class TravelingThiefLocalSearch : public LocalSearch {
  public:
    TravelingThiefDatabase * database;
    TravelingThiefLocalSearch();
    TravelingThiefIndividual* doLocalSearch(Individual* s1);
    virtual ~TravelingThiefLocalSearch();

    TravelingThiefIndividual* TwoOpt(TravelingThiefIndividual * s1_);
    void TwoOptSwap(TravelingThiefIndividual* s1, TravelingThiefIndividual* s2, const int& i, const int& k);
    TravelingThiefIndividual *knapsackLocalSearch(TravelingThiefIndividual* s);

    void setDatabase(TravelingThiefDatabase * database);

  protected:

  private:
    static bool sortPopulationByFitness(Individual* a, Individual* b);
};

#endif // TRAVELINGTHIEFLOCALSEARCH_H
