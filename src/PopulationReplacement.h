#ifndef POPULATIONREPLACEMENT_H
#define POPULATIONREPLACEMENT_H

#include "Individual.h"

class PopulationReplacement {
  public:
    PopulationReplacement();

    virtual void Replace(Individual **pop) = 0;

    virtual ~PopulationReplacement();

  protected:

  private:
};

#endif // POPULATIONREPLACEMENT_H
