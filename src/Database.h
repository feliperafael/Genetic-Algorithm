#ifndef DATABASE_H
#define DATABASE_H
#include <string>

using namespace std;

class Database
{
    public:
        Database();

        void loadBase(string base);
        double* getRegister(int position);

        void print();


        virtual ~Database();

    protected:

    private:
};

#endif // DATABASE_H
