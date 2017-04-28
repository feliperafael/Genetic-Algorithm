#ifndef TRAVELINGTHIEFPARSER_H
#define TRAVELINGTHIEFPARSER_H

#include "Individual.h"
#include "Parser.h"
#include "TravelingThiefIndividual.h"
#include "TravelingThiefDatabase.h"
#include "City.h"

class TravelingThiefParser : public Parser
{
    public:
        TravelingThiefDatabase * database;
        TravelingThiefParser();

        double Evaluate(Individual* s);
        string nameParser();
        void setDatabase(Database * data);

        virtual ~TravelingThiefParser();

    protected:

    private:
        double calculateSpeed(TravelingThiefIndividual * s);
        double calculateProfit(TravelingThiefIndividual * s);
        double calculateDistance(City * a, City * b);
        double calculateTime(double distance, double speed);
};

#endif // TRAVELINGTHIEFPARSER_H
