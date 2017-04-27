#include "TravelingThiefIndividual.h"

TravelingThiefIndividual::TravelingThiefIndividual()
{
    //Allocates the matrix representing the individual
    cityBackpack = new int*[conf->num_citys];
    for(int i = 0; i < conf->num_citys; i++){
        cityBackpack[i] = new int[conf->max_itens];
    }
    for(int i = 0; i < conf->num_citys; i++){
        for(int j = 0; j < conf->max_itens; j++){
            cityBackpack[i][j] = rand();
        }
    }

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
    //Deallocates the matrix representing the individual
    for(int i = 0; i < conf->num_citys; i++){
        delete cityBackpack[i];
    }
    delete cityBackpack;
}
