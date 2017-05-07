#ifndef SIMPLEMUTATION_H
#define SIMPLEMUTATION_H

#include "Mutation.h"
#include "Individual.h"
#include "SimpleIndividual.h"

class SimpleMutation : public Mutation {
  public:
    SimpleMutation();
    virtual void mutate(Individual * individuo);
    virtual ~SimpleMutation();

  protected:

  private:
};

#endif // SIMPLEMUTATION_H
