#include "TravelingThiefIndividual.h"

TravelingThiefIndividual::TravelingThiefIndividual(TravelingThiefDatabase *database) {
//    if(database != NULL)
//        buildsRoute(database);

//    print();
//    cin.get();
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
    //City** c;//Vector of pointers to cities
    weightKnapsack = 0;
    amountOfCity = database->DIMENSION;

    cities = new City*[amountOfCity ];

    for(int i = 0; i < amountOfCity ; ++i) {
        cities[i] = database->cities.at(i);
    }

    // shuffles the vector
    std::random_shuffle ( cities + 1, cities+amountOfCity ); //first and last cities should not be modified
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

    knapsack = new vector<Item*>[amountOfCity];

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
    knapsack[item->city].push_back(item);
    this->weightKnapsack += item->weight;
}

bool TravelingThiefIndividual::knapsackAcceptsItem(Item * item) {
    if(this->weightKnapsack + item->weight < conf->CAPACITY_OF_KNAPSACK)
        return true;

    return false;
}

void TravelingThiefIndividual::print() {
    cout << fitness << ", " << weightKnapsack << ", " << conf->CAPACITY_OF_KNAPSACK << endl;
    for(int i = 0; i < amountOfCity; i++){
        cout << cities[i]->index << " ";
//        for(Item* item : knapsack[i])
//            cout << item->index << " ";
//        cout << endl;
    }
    cout << endl;
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
    std::sort( cities + 1, cities+amountOfCity, SortCitiesByDistanceCost ); //first and last cities should not be modified

    for(int i = 0; i < amountOfCity ; ++i) {
        for(int j = i; j < amountOfCity -1; j++){
             if(calculateDistance(cities[i], cities[j])/cities[j]->getCostBenefit() > calculateDistance(cities[i], cities[j+1])/cities[j+1]->getCostBenefit()){
                if(rand()%100 < 95)
                    swap(cities[j],cities[j+1]);
             }
        }

    }
    buildKsnapsack(database);
}
/** Calculates the Euclidean distance between two cities **/
double TravelingThiefIndividual::calculateDistance(City * a, City * b){
    return sqrt(pow(a->x - b->x,2) + pow(a->y - b->y,2));
}

bool TravelingThiefIndividual::SortCitiesByDistanceCost(City* a, City* b){
    if(a->getCostBenefit() > b->getCostBenefit())
        return true;
    return false;
 }


TravelingThiefIndividual::~TravelingThiefIndividual() {
    delete [] cities;
    for(int i = 0; i < amountOfCity; i++){
        knapsack[i].clear();
        knapsack[i].shrink_to_fit();
    }

    delete [] knapsack;
}
