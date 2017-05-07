#ifndef TRAVELINGTHIEFPARSER_H
#define TRAVELINGTHIEFPARSER_H

#include "Individual.h"
#include "Parser.h"
#include "TravelingThiefIndividual.h"
#include "TravelingThiefDatabase.h"
#include "City.h"

class TravelingThiefParser : public Parser {
  public:
    double ** distanceCities;//Lower triangular matrix with distances between cities

    TravelingThiefDatabase * database;
    TravelingThiefParser();

    double Evaluate(Individual* s);
    string nameParser();
    void setDatabase(Database * data);

    virtual ~TravelingThiefParser();

  protected:

  private:
    double alphaConstant;

    double calculateSpeed(TravelingThiefIndividual * s);
    double calculateProfit(TravelingThiefIndividual * s);
    double calculateDistance(City * a, City * b);
    double calculateTime(double distance, double speed);

    double calculateDistanceAB(City * a, City * b);

    void   caculalateDistanceMatrix();
    int    calculateDistanceMatrixIndices(int i, int j);

};

#endif // TRAVELINGTHIEFPARSER_H
