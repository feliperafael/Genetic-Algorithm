#ifndef CROSSOVER_H
#define CROSSOVER_H

#include "Individual.h"

class Crossover {
  public:
    Crossover();
    virtual void cross(Individual ** vec_individuos, int num_individuos) = 0;
    virtual ~Crossover();

  protected:

  private:
};

#endif // CROSSOVER_H
