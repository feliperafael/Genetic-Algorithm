#ifndef ITEM_H
#define ITEM_H

#include <iostream>

using namespace std;

class Item
{
    public:
        int index, city;
        double profit, weight;

        Item();
        void setObject(int, double, double, int);
        void setIndex(int index);
        void setProfit(double Profit);
        void setWeight(double weight);
        void setCity(int city);
        void print();
        virtual ~Item();

    protected:

    private:
};

#endif // ITEM_H
