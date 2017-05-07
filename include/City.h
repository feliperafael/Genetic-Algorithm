#ifndef CITY_H
#define CITY_H

#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class City {
  public:
    int index, x, y;
    vector<Item*> items;
    double costBenefit;

    City();
    void setObject(int index, int x, int y);
    void setIndex(int index);
    void setX(int x);
    void setY(int y);
    void addItem(Item * item);
    double getCostBenefit();
    void print();
    virtual ~City();

  protected:

  private:
};

#endif // CITY_H
