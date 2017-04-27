#include "Item.h"

Item::Item()
{
    //ctor
}

void Item::setObject(int index, double profit, double weight, int city){
    this->index = index;
    this->profit = profit;
    this->weight = weight;
    this->city = city;
}

void Item::setIndex(int index){
    this->index = index;
}

void Item::setProfit(double profit){
    this->profit = profit;
}

void Item::setWeight(double weight){
    this->weight = weight;
}

void Item::setCity(int city){
    this->city = city;
}

void Item::print(){
    cout << "[" << index << ", " << profit << ", " << weight << ", " << city << "]" << endl;
}

Item::~Item()
{
    //dtor
}
