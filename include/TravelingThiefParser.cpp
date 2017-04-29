#include "TravelingThiefParser.h"

TravelingThiefParser::TravelingThiefParser()
{
    distanceCities = new double*[conf->DIMENSION];

    for(int i = 0; i < conf->DIMENSION; ++i){
        distanceCities[i] = new double[conf->DIMENSION];
    }

    //ctor
}

double TravelingThiefParser::Evaluate(Individual* s)
{
    TravelingThiefIndividual * s1 = dynamic_cast<TravelingThiefIndividual*>(s);

    double time = 0, profit = 0, speed = 0, distance = 0;
    s1->weightKnapsack = 0;
    for(int i = 1; i < s1->amountOfCity; ++i){
        distance = calculateDistance(s1->cities[i], s1->cities[i - 1]);
        speed = calculateSpeed(s1);
        time += calculateTime(distance, speed);

        for(Item* item : s1->knapsack[i]){
            s1->weightKnapsack += item->weight;
            profit += item->profit;
            //cout <<  s1->weightKnapsack <<" - " << profit << endl;cin.get();
        }
    }
//    if(profit - database->RENTING_RATIO * time > 2000){
//        cout << profit << " - " << database->RENTING_RATIO << " * " << time << endl; cin.get();
//    }

    /// Change the profit name to anything related to value items
    return s1->fitness = profit - database->RENTING_RATIO * time;
}

void TravelingThiefParser::setDatabase(Database * data){
    this->database = dynamic_cast<TravelingThiefDatabase*>(data);
    caculalateDistanceMatrix();
    //database->print();
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
    for(int i = 0; i < s->amountOfCity; i++){
        for(Item* item : s->knapsack[i]){
            profit += item->profit;
        }
    }

    return profit;
}


/** Return the Euclidean distance of distance matriz **/
double TravelingThiefParser::calculateDistance(City * a, City * b){
    return distanceCities[a->index][b->index];
}

/** Calculates the Euclidean distance between two cities **/
double TravelingThiefParser::calculateDistanceAB(City * a, City * b){
    return sqrt(pow(a->x - b->x,2) + pow(a->y - b->y,2));
}

/** Calculates the travel time between two cities **/
double TravelingThiefParser::calculateTime(double distance, double speed){
    return distance/speed;
}

int TravelingThiefParser::calculateDistanceMatrixIndices(int i, int j){
   return int((i*i + i)/2 + j);
}

void TravelingThiefParser::caculalateDistanceMatrix(){
    for(int i = 0; i < database->cities.size(); i++){
        for(int j = 0; j < database->cities.size(); j++){
            distanceCities[j][i] = calculateDistanceAB(database->cities[i],database->cities[j]);
        }
    }
}

string TravelingThiefParser::nameParser()
{
    return "TravelingThiefParser";
}

TravelingThiefParser::~TravelingThiefParser()
{
    //dtor
}
