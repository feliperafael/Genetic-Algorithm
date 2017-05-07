#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <string>
#include "Configures.h"
#include "Individual.h"

using namespace std;

class Individual {
  public:
    double fitness;

    Individual();

    virtual string nameIndividual() = 0; // print name of individual
    virtual Individual* clone() = 0;
    virtual void print() = 0;

    virtual ~Individual();

  protected:

  private:
};

#endif // INDIVIDUAL_H
