#include "TravelingThiefParser.h"

TravelingThiefParser::TravelingThiefParser() {
    distanceCities = new double*[conf->DIMENSION];

    for(int i = 0; i < conf->DIMENSION; ++i) {
        distanceCities[i] = new double[conf->DIMENSION];
    }

    alphaConstant = (database->MAX_SPEED - database->MIN_SPEED)/database->CAPACITY_OF_KNAPSACK;

}

double TravelingThiefParser::Evaluate(Individual* s) {
    TravelingThiefIndividual * s1 = dynamic_cast<TravelingThiefIndividual*>(s);
    s1->fitness = 0;
    double time = 0, profit = 0, speed = 0, distance = 0;
    s1->weightKnapsack = 0;
    s1->distance = 0;
    int amountOfCity = s1->amountOfCity;
    for(int i = 1; i < amountOfCity; ++i) {
        distance = calculateDistance(s1->cities[i], s1->cities[i - 1]);
        s1->distance += distance;
        speed = calculateSpeed(s1);
        time += calculateTime(distance, speed);

        for(Item* item : s1->knapsack[i]) {
            s1->weightKnapsack += item->weight;
            profit += item->profit;
        }
    }

    s1->time = time;
    /// Change the profit name to anything related to value items
    s1->fitness = profit - database->RENTING_RATIO * time;
    return s1->fitness;
}

void TravelingThiefParser::setDatabase(Database * data) {
    this->database = dynamic_cast<TravelingThiefDatabase*>(data);
    caculalateDistanceMatrix();
    //database->print();
}

/**
    Va = Vmax − Wa (Vmax−Vmin )/W, sendo Va a velocidade atual,
    Vmax a velocidade máxima, Vmin a velocidade mínima, Wa o
    peso atual da mochila e W a capacidade máxima da mochila

**/
double TravelingThiefParser::calculateSpeed(TravelingThiefIndividual * s) {
    return database->MAX_SPEED - s->weightKnapsack*alphaConstant;
    /// alphaConstant is (database->MAX_SPEED - database->MIN_SPEED)/database->CAPACITY_OF_KNAPSACK
}

double TravelingThiefParser::calculateProfit(TravelingThiefIndividual * s) {
    double profit = 0;
    int amountOfCity = s->amountOfCity;
    for(int i = 0; i < amountOfCity; ++i) {
        for(Item* item : s->knapsack[i]) {
            profit += item->profit;
        }
    }
    return profit;
}


/** Return the Euclidean distance of distance matriz **/
double TravelingThiefParser::calculateDistance(City * a, City * b) {
    return distanceCities[a->index][b->index];
}

/** Calculates the Euclidean distance between two cities **/
double TravelingThiefParser::calculateDistanceAB(City * a, City * b) {
    return sqrt(pow(a->x - b->x,2) + pow(a->y - b->y,2));
}

/** Calculates the travel time between two cities **/
double TravelingThiefParser::calculateTime(double distance, double speed) {
    return distance/speed;
}

int TravelingThiefParser::calculateDistanceMatrixIndices(int i, int j) {
    return int((i*i + i)/2 + j);
}

void TravelingThiefParser::caculalateDistanceMatrix() {
    int cities_size = database->cities.size();
    for(int i = 0; i < cities_size; ++i) {
        for(int j = 0; j < cities_size; ++j) {
            distanceCities[j][i] = calculateDistanceAB(database->cities[i],database->cities[j]);
        }
    }
}

string TravelingThiefParser::nameParser() {
    return "TravelingThiefParser";
}

TravelingThiefParser::~TravelingThiefParser() {

}
