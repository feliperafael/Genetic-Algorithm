#ifndef INDIVIDUALSELECTOR_H
#define INDIVIDUALSELECTOR_H

#include "Individual.h"

class IndividualSelector {
  public:
    IndividualSelector();
    virtual Individual * selects(Individual ** pop) = 0;
    virtual ~IndividualSelector();

  protected:

  private:
};

#endif // INDIVIDUALSELECTOR_H
