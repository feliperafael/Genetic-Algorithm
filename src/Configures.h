#ifndef CONFIGURES_H
#define CONFIGURES_H


class Configures
{
    public:
        Configures();

        int popSize;
        int generations;
        virtual ~Configures();

    protected:

    private:
};

extern Configures* conf;

#endif // CONFIGURES_H
