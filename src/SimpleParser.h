#ifndef SIMPLEPARSER_H
#define SIMPLEPARSER_H
#include "Parser.h"

class SimpleParser : public Parser
{
    public:
        SimpleParser();
        virtual ~SimpleParser();

        virtual double Evaluate(Individual* s);
        virtual string nameParser();

    protected:

    private:
};

#endif // SIMPLEPARSER_H
