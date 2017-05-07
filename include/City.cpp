#include "City.h"

City::City() {
    //ctor
}

void City::setObject(int index, int x, int y) {
    this->index = index;
    this->x = x;
    this->y = y;
}

void City::setIndex(int index) {
    this->index = index;
}

void City::setX(int x) {
    this->x = x;
}

void City::setY(int y) {
    this->y = y;
}

void City::addItem(Item * item) {
    items.push_back(item);
}

double City::getCostBenefit() {
    double costBenefit = 0;
    for(Item * item : items)
        costBenefit+= item->getCostBenefit();
    return costBenefit;
}

void City::print() {
    cout << "(" << index << ", " << x << ", " << y << ")" << endl;
    cout << "(" << index << ", " << x << ", " << y << ") = " << items.size() << endl;
    for(Item * item : items) {
        cout << "     ";
        item->print();
    }
}

City::~City() {
    Item * itemAux;
    for(vector<Item*>::iterator it = items.begin(); it != items.end(); ++it) {
        itemAux = *it;
        delete itemAux;
    }
    items.clear();
    items.shrink_to_fit();
}
