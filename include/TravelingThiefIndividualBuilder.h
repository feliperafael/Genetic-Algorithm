#ifndef TRAVELINGTHIEFBUILDERINDIVIDUAL_H
#define TRAVELINGTHIEFBUILDERINDIVIDUAL_H
#include "IndividualBuilder.h"
#include "TravelingThiefIndividual.h"
#include "TravelingThiefDatabase.h"
#include "Database.h"

class TravelingThiefIndividualBuilder : public IndividualBuilder {
  public:
    TravelingThiefDatabase * database;
    TravelingThiefIndividualBuilder(Database * database);

    Individual * generateIndividuo();
    string nameIndividuo();

    virtual ~TravelingThiefIndividualBuilder();

  protected:

  private:
};

#endif // TRAVELINGTHIEFBUILDERINDIVIDUAL_H
