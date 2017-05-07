#ifndef SIMPLEINDIVIDUAL_H
#define SIMPLEINDIVIDUAL_H
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include "Individual.h"

using namespace std;

class SimpleIndividual : public Individual {
  public:
    double x;
    bool a;
    SimpleIndividual();

    virtual string nameIndividual(); // print name of individual
    virtual Individual* clone();
    virtual void print();

    virtual ~SimpleIndividual();

  protected:

  private:
};

#endif // SIMPLEINDIVIDUAL_H
