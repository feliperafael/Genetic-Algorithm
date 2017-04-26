#ifndef CONFIGURES_H
#define CONFIGURES_H


class Configures
{
    public:
        Configures();

        int popSize;
        int generations;

        int num_citys;
        int max_itens;

        virtual ~Configures();

    protected:

    private:
};

extern Configures * conf;

#endif // CONFIGURES_H
