#ifndef TRAVELINGTHIEFPARSER_H
#define TRAVELINGTHIEFPARSER_H

#include "Individual.h"

class TravelingThiefParser
{
    public:
        TravelingThiefParser();

        double Evaluate(Individual* s);
        string nameParser();

        virtual ~TravelingThiefParser();

    protected:

    private:
};

#endif // TRAVELINGTHIEFPARSER_H
