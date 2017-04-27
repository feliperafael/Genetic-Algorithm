#ifndef CONFIGURES_H
#define CONFIGURES_H


class Configures
{
    public:
        Configures();

        int popSize;
        double elitism;
        int generations;
        double crossover;
        int MAX_T = 1;

        int num_citys;
        int max_itens;

        virtual ~Configures();

    protected:

    private:
};

extern Configures * conf;

#endif // CONFIGURES_H
