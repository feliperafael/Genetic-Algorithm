#ifndef LOCALSEARCH_H
#define LOCALSEARCH_H

#include "Individual.h"
#include "Parser.h"

class LocalSearch {
  public:
    LocalSearch();
    virtual Individual* doLocalSearch(Individual* s1) = 0;
    virtual ~LocalSearch();

    void setParser(Parser* parser);

    Parser* parser;
  protected:

  private:
};

#endif // LOCALSEARCH_H
