#ifndef SIMPLECROSSOVER_H
#define SIMPLECROSSOVER_H
#include <stdlib.h>     /* srand, rand */

#include "Crossover.h"
#include "SimpleIndividual.h"


class SimpleCrossover : public Crossover {
  public:
    SimpleCrossover();
    virtual void cross(Individual ** vec_individuos, int num_individuos);
    virtual ~SimpleCrossover();

  protected:

  private:
};

#endif // SIMPLECROSSOVER_H
