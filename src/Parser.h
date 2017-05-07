#ifndef PARSER_H
#define PARSER_H

#include <string>
#include "Individual.h"

class Parser {
  public:
    Parser();

    virtual double Evaluate(Individual* s) = 0;
    virtual string nameParser() = 0;

    virtual ~Parser();

  protected:

  private:
};

#endif // PARSER_H
