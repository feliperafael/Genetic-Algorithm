#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Database {
  public:
    double **values;
    int registros;
    int variaveis;
    Database();

    virtual void loadBase(string base_name);
    virtual double* getRegister(int position);

    virtual void print();


    virtual ~Database();

  protected:

  private:
};

#endif // DATABASE_H
