#ifndef SIMPLEREPLACEMENT_H
#define SIMPLEREPLACEMENT_H

#include "PopulationReplacement.h"
#include <algorithm>    // std::sort

class SimpleReplacement : public PopulationReplacement
{
    public:
        SimpleReplacement();

        /**
            recebe um população de individuos de tamanho conf->PopSize*2 e deixa os individuos a serem mantidos
            no intervalo de [0,pop->conf)
        **/
        virtual void Replace(Individual **pop);

        virtual ~SimpleReplacement();

    protected:

    private:
       static bool SortMyPop(Individual* a, Individual* b);
};

#endif // SIMPLEREPLACEMENT_H
