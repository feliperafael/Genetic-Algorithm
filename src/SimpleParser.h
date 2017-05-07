#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H
#include <math.h>

#include "Database.h"
#include "Parser.h"
#include "SimpleIndividual.h"


class SimpleParser : public Parser {
  public:
    Database * database;
    SimpleParser();
    virtual ~SimpleParser();

    virtual double Evaluate(Individual* s);
    virtual string nameParser();
    void setDatabase(Database * data);

  protected:

  private:
};

#endif // SIMPLEPARSER_H
