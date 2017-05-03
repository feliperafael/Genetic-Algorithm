#include "TravelingThiefLocalSearch.h"

TravelingThiefLocalSearch::TravelingThiefLocalSearch()
{
    //ctor
}

void TravelingThiefLocalSearch::doLocalSearch(Individual* s1){
    TwoOpt(dynamic_cast<TravelingThiefIndividual*>(s1));
    (dynamic_cast<TravelingThiefIndividual*>(s1))->print();
}

void TravelingThiefLocalSearch::TwoOpt(TravelingThiefIndividual* s1)
{
    // Get tour size
    int size = s1->amountOfCity;

    // repeat until no improvement is made
    int improve = 0;

    TravelingThiefIndividual* s2;

    while (improve == 0){
        double best_distance = s1->distance;

        for ( int i = 0; i < size - 1; i++ ){
            for ( int k = i + 1; k < size; k++){
                s2 = dynamic_cast<TravelingThiefIndividual*>(s1->clone());
                TwoOptSwap(s1, s2, i, k);
//                s2->print();
                double new_distance = s2->distance;

                if ( new_distance < best_distance )
                {
//                     Improvement found so reset
                    cout << "newDistance " << new_distance << " bestDistance " << best_distance << endl;
                    improve++;

//                    delete s1;

//                    *s1 = *s2;
                    TravelingThiefIndividual* aux = s1;
                    s1 = s2;
                    s2 = aux;
//                    delete s2;
                    best_distance = new_distance;
                }
//                else{
                    delete s2;
//                }
            }
        }
        cout << improve << endl;
//        cin.get();
    }
    s1->print();
}

void TravelingThiefLocalSearch::TwoOptSwap(TravelingThiefIndividual* s1, TravelingThiefIndividual* s2, const int& i, const int& k )
{
    int size = s1->amountOfCity;

    // 1. take route[0] to route[i-1] and add them in order to new_route
    for ( int c = 0; c <= i - 1; ++c )
    {
        s2->cities[c] = s1->cities[c];
    }

    // 2. take route[i] to route[k] and add them in reverse order to new_route
    int dec = 0;
    for ( int c = i; c <= k; ++c )
    {
        s2->cities[c] = s1->cities[k - dec];
        dec++;
    }

    // 3. take route[k+1] to end and add them in order to new_route
    for ( int c = k + 1; c < size; ++c )
    {
        s2->cities[c] = s1->cities[c];
    }

    parser->Evaluate(s2);
}

TravelingThiefLocalSearch::~TravelingThiefLocalSearch()
{
    //dtor
}
