#ifndef MUTATION_H
#define MUTATION_H
#include "Individual.h"

class Mutation {
  public:
    Mutation();
    virtual void mutate(Individual * individuo) = 0;
    virtual ~Mutation();

  protected:

  private:
};

#endif // MUTATION_H
