#include "TravelingThiefParser.h"

TravelingThiefParser::TravelingThiefParser()
{
    //ctor
}

double TravelingThiefParser::Evaluate(Individual* s)
{
    TravelingThiefIndividual * s1 = dynamic_cast<TravelingThiefIndividual*>(s);

    double time = 0, profit = 0, speed, distance;
    s1->weightKnapsack = 0;
    for(int i = 1; i < s1->amountOfCity; ++i){
        distance = calculateDistance(s1->cities[i], s1->cities[i - 1]);
        speed = calculateSpeed(s1);
        time += calculateTime(distance, speed);

        for( int j = 0; j < s1->knapsack.size(); ++j){
             if(s1->knapsack.at(j)->city == s1->cities[i]->index){
                s1->weightKnapsack += s1->knapsack.at(j)->weight;
                profit += s1->knapsack.at(j)->profit;
            }
        }

    }
    /// Change the profit name to anything related to value items
    return s1->fitness = profit - database->RENTING_RATIO * time;
}

void TravelingThiefParser::setDatabase(Database * data){
    this->database = dynamic_cast<TravelingThiefDatabase*>(data);
    database->print();
 }

/**
    Va = Vmax − Wa (Vmax−Vmin )/W, sendo Va a velocidade atual,
    Vmax a velocidade máxima, Vmin a velocidade mínima, Wa o
    peso atual da mochila e W a capacidade máxima da mochila

**/
double TravelingThiefParser::calculateSpeed(TravelingThiefIndividual * s){
    return database->MAX_SPEED - s->weightKnapsack*(database->MAX_SPEED - database->MIN_SPEED)/database->CAPACITY_OF_KNAPSACK;
}

double TravelingThiefParser::calculateProfit(TravelingThiefIndividual * s){
    double profit = 0;
    for(Item* item : s->knapsack){
        profit += item->profit;
    }

    return profit;
}

/** Calculates the Euclidean distance between two cities **/
double TravelingThiefParser::calculateDistance(City * a, City * b){
   return sqrt(pow(a->x - b->x,2) + pow(a->y - b->y,2));
}

/** Calculates the travel time between two cities **/
double TravelingThiefParser::calculateTime(double distance, double speed){
    return speed/distance;
}

string TravelingThiefParser::nameParser()
{
    return "TravelingThiefParser";
}

TravelingThiefParser::~TravelingThiefParser()
{
    //dtor
}
