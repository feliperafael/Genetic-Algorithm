#ifndef SIMPLEINDIVIDUALBUILDER_H
#define SIMPLEINDIVIDUALBUILDER_H

#include "IndividualBuilder.h"
#include "SimpleIndividual.h"

class SimpleIndividualBuilder : public IndividualBuilder {
  public:
    SimpleIndividualBuilder();
    virtual ~SimpleIndividualBuilder();
    virtual Individual * generateIndividuo();
    virtual string nameIndividuo();


  protected:

  private:
};

#endif // SIMPLEINDIVIDUALBUILDER_H
