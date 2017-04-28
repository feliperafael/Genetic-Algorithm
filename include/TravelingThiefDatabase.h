#ifndef TRAVELINGTHIEFDATABASE_H
#define TRAVELINGTHIEFDATABASE_H
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cctype>

#include "Configures.h"
#include "Database.h"
#include "City.h"
#include "Item.h"

using namespace std;

class TravelingThiefDatabase : public Database
{
    public:
        TravelingThiefDatabase();
        string PROBLEM_NAME;
        string KNAPSACK_DATA_TYPE;
        int DIMENSION;
        int NUMBER_OF_ITEMS;
        int CAPACITY_OF_KNAPSACK;
        double MIN_SPEED;
        double MAX_SPEED;
        double RENTING_RATIO;
        string EDGE_WEIGHT_TYPE;

        vector<City*> cities;

        void loadBase(string base_name);

        void print(){}
        void printInstanceHeader();

        virtual ~TravelingThiefDatabase();

    protected:

    private:
        const vector<string> explode(const string& s, const char& c);
        string remove_space(string input);
};

#endif // TRAVELINGTHIEFDATABASE_H
