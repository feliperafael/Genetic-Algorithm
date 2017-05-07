#ifndef SIMPLEREPLACEMENT_H
#define SIMPLEREPLACEMENT_H

#include "PopulationReplacement.h"
#include <algorithm>    // std::sort

class SimpleReplacement : public PopulationReplacement {
  public:
    SimpleReplacement();

    /**
       Receives a population of individuals of size conf-> PopSize * 2 and leaves the individuals to be maintained
               In the range of [0,pop->conf)
    **/
    virtual void Replace(Individual **pop);

    virtual ~SimpleReplacement();

  protected:

  private:
    static bool SortMyPop(Individual* a, Individual* b);
};

#endif // SIMPLEREPLACEMENT_H
