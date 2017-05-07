#include "TravelingThiefIndividual.h"

TravelingThiefIndividual::TravelingThiefIndividual(TravelingThiefDatabase *database) {

}

string TravelingThiefIndividual::nameIndividual() {
    return "TravelingThiefIndividual";
}
Individual* TravelingThiefIndividual::clone() {
    TravelingThiefIndividual * i = new TravelingThiefIndividual(NULL);
    i->amountOfCity = amountOfCity;
    i->fitness = fitness;
    i->weightKnapsack = weightKnapsack;
    i->cities = new City*[amountOfCity];
    i->knapsack = new vector<Item*>[amountOfCity];
    for(int k = 0; k < amountOfCity; ++k){
        i->cities[k] = cities[k];
        for(Item* item : knapsack[k])
            i->knapsack[k].push_back(item);
    }
    return i;

}

void TravelingThiefIndividual::buildsRoute(TravelingThiefDatabase * database) {

    weightKnapsack = 0;
    amountOfCity = database->DIMENSION;

    cities = new City*[amountOfCity ];

    for(int i = 0; i < amountOfCity ; ++i) {
        cities[i] = database->cities.at(i);
    }

    // shuffles the vector
    std::random_shuffle ( cities + 1, cities+amountOfCity ); //first and last cities should not be modified

   if(rand()%2==0)
        smartBuildKsnapsack();
    else
        buildKsnapsack();

}

void TravelingThiefIndividual::buildsFartherFirstRoute(TravelingThiefDatabase * database){

 //City** c;//Vector of pointers to cities
    weightKnapsack = 0;
    amountOfCity = database->DIMENSION;

    cities = new City*[amountOfCity ];

    for(int i = 0; i < amountOfCity ; ++i) {
        cities[i] = database->cities.at(i);
    }


    // shuffles the vector
    std::sort( cities + 1, cities+amountOfCity, sortCitiesByBiggerDistanceCost ); //first city should not be modified

    for(int i = 0; i < amountOfCity - 1; ++i) {

        int p = i + 1;
        double distanceip = calculateDistance(cities[i], cities[p]);
        for(int j = i+2; j < amountOfCity; j++){

            if(distanceip/cities[p]->getCostBenefit() > calculateDistance(cities[i], cities[j])/cities[j]->getCostBenefit()){
                if(rand()%100 < 30){
                    p = j;
                    distanceip = calculateDistance(cities[i], cities[j]);
                }
            }
        }
        swap(cities[p], cities[i + 1]);
    }

    if(rand()%2==0)
        smartBuildKsnapsack();
    else
        buildKsnapsack();
}

void TravelingThiefIndividual::buildKsnapsack() {
    City *c;

    knapsack = new vector<Item*>[amountOfCity];

    for(int i = 0; i < amountOfCity; ++i) {
        c = cities[i];
            for(Item * item : c->items) {
                if(knapsackAcceptsItem(item)) {
                    addOnKnapsack(item);
                }
            }
    }
}

void TravelingThiefIndividual::smartBuildKsnapsack(){
    City *c;
    knapsack = new vector<Item*>[amountOfCity];
    vector<Item*> auxKnapsack;

    for(int i = 0; i < amountOfCity; ++i) {
        c = cities[i];
        for(Item * item : c->items) {
            auxKnapsack.push_back(item);
        }
    }
    sort(auxKnapsack.begin(),auxKnapsack.end(),sortItemsByCostWeight);


    for(Item * item : auxKnapsack) {
        if(knapsackAcceptsItem(item)) {
            addOnKnapsack(item);
        }
    }
}

void TravelingThiefIndividual::addOnKnapsack(Item *item){

    knapsack[item->city].push_back(item);
    this->weightKnapsack += item->weight;
}

void TravelingThiefIndividual::removeOnKnapsack(int city, int itemIndex){
    Item * item = knapsack[city].at(itemIndex);
    if(item!=NULL){
        this->weightKnapsack -= item->weight;
        knapsack[city].erase( knapsack[city].begin() + itemIndex);
    }
}

bool TravelingThiefIndividual::knapsackAcceptsItem(Item * item) {
    //Check restriction
    if(this->weightKnapsack + item->weight < conf->CAPACITY_OF_KNAPSACK){
        return true;
    }

    return false;
}

void TravelingThiefIndividual::print() {
    bool aux = false;

    cout << fitness << " " << weightKnapsack << " " << distance << " " << conf->seed << " ";
    for(int i = 0; i < amountOfCity; i++){
        cout << "[" << cities[i]->index << " (";
        for(Item* item : cities[i]->items){
            if(knapsack[i].size() > 1 && aux == true){
                cout << ",";
            }
            cout << item->index;
            aux = true;
        }
        aux = false;
        cout << ")] => ";
    }
}

void TravelingThiefIndividual::buildRouteOfLeastPath(TravelingThiefDatabase * database){

     //City** c;//Vector of pointers to cities
    weightKnapsack = 0;
    amountOfCity = database->DIMENSION;

    cities = new City*[amountOfCity ];

    for(int i = 0; i < amountOfCity ; ++i) {
        cities[i] = database->cities.at(i);
    }

    // shuffles the vector
    std::sort( cities + 1, cities+amountOfCity, sortCitiesByDistanceCost ); //first city should not be modified

    for(int i = 0; i < amountOfCity - 1; ++i) {

        int p = i + 1;
        double distanceip = calculateDistance(cities[i], cities[p]);
        for(int j = i+2; j < amountOfCity; j++){

            if(distanceip/cities[p]->getCostBenefit() > calculateDistance(cities[i], cities[j])/cities[j]->getCostBenefit()){
                if(rand()%100 < 60){
                    p = j;
                    distanceip = calculateDistance(cities[i], cities[j]);
                }
            }
        }
        swap(cities[p], cities[i + 1]);
    }

    if(rand()%2==0)
        smartBuildKsnapsack();
    else
        buildKsnapsack();
}
/** Calculates the Euclidean distance between two cities **/
double TravelingThiefIndividual::calculateDistance(City * a, City * b){
    return sqrt(pow(a->x - b->x,2) + pow(a->y - b->y,2));
}

bool TravelingThiefIndividual::sortCitiesByDistanceCost(City* a, City* b){
    if(a->getCostBenefit() > b->getCostBenefit())
        return true;
    return false;
 }

bool TravelingThiefIndividual::sortCitiesByBiggerDistanceCost(City* a, City* b){
    if(a->getCostBenefit() < b->getCostBenefit())
        return true;
    return false;
}

 void TravelingThiefIndividual::cleanKnapsack(){
     weightKnapsack = 0;
     for(int i = 0; i < amountOfCity; i++){
        knapsack[i].clear();
        knapsack[i].shrink_to_fit();
    }

    delete [] knapsack;
 }

 bool TravelingThiefIndividual::sortItemsByCostWeight(Item* a, Item* b){
    if(a->getCostBenefit() > b->getCostBenefit())
        return true;
    return false;
 }


TravelingThiefIndividual::~TravelingThiefIndividual() {
    delete [] cities;
    cleanKnapsack();
}
