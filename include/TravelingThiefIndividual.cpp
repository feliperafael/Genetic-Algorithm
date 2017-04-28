#include "TravelingThiefIndividual.h"

TravelingThiefIndividual::TravelingThiefIndividual(TravelingThiefDatabase *database) {
    weightKnapsack = 0;
    if(database !=NULL)
        buildsRoute(database);
}

string TravelingThiefIndividual::nameIndividual() {
    return "TravelingThiefIndividual";
}
Individual* TravelingThiefIndividual::clone() {
    TravelingThiefIndividual * i = new TravelingThiefIndividual(NULL);
    i->amountOfCity = amountOfCity;
    i->fitness = fitness;
    i->knapsack = knapsack;
    i->weightKnapsack = weightKnapsack;
    i->cities = new City*[amountOfCity];
    for(int k = 0; k < amountOfCity; ++k)
        i->cities[k] = cities[k];
    return i;

}

void TravelingThiefIndividual::buildsRoute(TravelingThiefDatabase * database) {

    //City** c;//Vector of pointers to cities
    this->amountOfCity = database->DIMENSION;
    cities = new City*[database->DIMENSION];

    for(int i = 0; i < database->DIMENSION; ++i) {
        cities[i] = database->cities.at(i);
    }

    // shuffles the vector
    std::random_shuffle ( cities + 1, cities+database->DIMENSION -1 ); //first and last cities should not be modified
    buildKsnapsack(database);

//    for(int i = 0; i < database->DIMENSION; ++i){
//        c[i]->print();
//        cin.get();
//    }
//   for(City *city : c){
//        cities.push_back(city);
//        for(Item *item : city->items){
//            city->items.push_back(item);
//            this->knapsack.push_back(item);
//            this->weightKnapsack += item->weight;
//        }
//   }
//   c.erase( c.begin(), c.end() );
//   cout <<  database->DIMENSION;
//   cin.get();
//    cout << this->weightKnapsack;
//    cin.get();
}

void TravelingThiefIndividual::buildKsnapsack(TravelingThiefDatabase * database) {
    City *c;
    int itemSize = 0;

    for(int i = 0; i < database->DIMENSION; ++i) {
        c = cities[i];
        itemSize = c->items.size();
        for(int j = 0; j < itemSize; ++j) {
            for(Item * item : c->items) {
                if(knapsackAcceptsItem(item)) {
                    addOnKnapsack(item);
                }
            }
        }
    }
}

void TravelingThiefIndividual::addOnKnapsack(Item *item){
    knapsack.push_back(item);
    this->weightKnapsack += (item)->weight;
}

bool TravelingThiefIndividual::knapsackAcceptsItem(Item * item) {
    if(this->weightKnapsack + item->weight < conf->CAPACITY_OF_KNAPSACK)
        return true;
//    if(rand()%100 < 5){ //5% chance of accepting a non-viable solution
//        return true;
//    }
    return false;
}

void TravelingThiefIndividual::print() {
    this->knapsack.size();
    cout << fitness << ", " <<  this->knapsack.size() << ", " << weightKnapsack << endl;

}


TravelingThiefIndividual::~TravelingThiefIndividual() {

    for(int i = 0; i < amountOfCity; i++)
    {
        cities[i] = NULL;
        delete cities[i];
    }


    // clear knapsack haha

//   Item * itemAux;
//    for(vector<Item*>::iterator it = knapsack.begin(); it != knapsack.end(); ++it) {
//        itemAux = *it;
//        delete itemAux;
//    }
//    knapsack.clear();
//    knapsack.shrink_to_fit();

}
