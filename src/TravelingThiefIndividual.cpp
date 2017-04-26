#include "TravelingThiefIndividual.h"

TravelingThiefIndividual::TravelingThiefIndividual()
{
    cityBackpack = new int*[conf->num_citys];

    for(int i = 0; i < conf->num_citys; i++){
        cityBackpack[i] = new int[conf->max_itens];
    }
    //ctor
}

string TravelingThiefIndividual::nameIndividual(){
    return "TravelingThiefIndividual";
}
Individual* TravelingThiefIndividual::clone(){

}
void TravelingThiefIndividual::print(){

    for(int i = 0; i < conf->num_citys; i++){
        cout << "cidade " << i << "itens : " << endl;
        for(int j = 0; j < conf->max_itens; i++){
            cout << cityBackpack[i] << " - ";
        }
        cout << endl;
    }

}


TravelingThiefIndividual::~TravelingThiefIndividual()
{
    //dtor
}
