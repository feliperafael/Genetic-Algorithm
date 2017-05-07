#ifndef INDIVIDUALBUILDER_H
#define INDIVIDUALBUILDER_H
#include "Individual.h"

class IndividualBuilder {
  public:
    IndividualBuilder();
    virtual ~IndividualBuilder();
    virtual Individual * generateIndividuo() = 0;
    virtual string nameIndividuo() = 0;

  protected:

  private:
};

#endif // INDIVIDUALBUILDER_H
