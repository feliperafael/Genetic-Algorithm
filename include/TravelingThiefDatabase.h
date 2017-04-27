#ifndef TRAVELINGTHIEFDATABASE_H
#define TRAVELINGTHIEFDATABASE_H
#include "Database.h"
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cctype>

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

        double **values;
        int registros;
        int variaveis;


        void loadBase(string base_name);
        double* getRegister(int position){}

        void print(){}
        void printInstanceHeader();

        virtual ~TravelingThiefDatabase();

    protected:

    private:
        const vector<string> explode(const string& s, const char& c);
        string remove_space(string input);
};

#endif // TRAVELINGTHIEFDATABASE_H
