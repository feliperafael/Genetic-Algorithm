#ifndef SIMPLEINDIVIDUALSELECTOR_H
#define SIMPLEINDIVIDUALSELECTOR_H
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "IndividualSelector.h"

class SimpleIndividualSelector : public IndividualSelector {
  public:
    SimpleIndividualSelector();
    virtual Individual * selects(Individual ** pop);
    virtual ~SimpleIndividualSelector();

  protected:

  private:
};

#endif // SIMPLEINDIVIDUALSELECTOR_H
