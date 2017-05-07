#include "Database.h"

Database::Database() {
    this->variaveis = 2;
    this->registros = 40;
}

void Database::loadBase(string base_name) {

    ifstream inputFile;

    inputFile.open(base_name.c_str());

    this->variaveis = 2;
    this->registros = 40;

    if(!inputFile.is_open()) {
        cout << "Impossible to open input file, check file path" << endl;
    } else {
#ifdef debug
        cout << base_name << " is opened" << endl;
#endif
    }

    //data array instance
    values = new double*[registros];
    for(int i = 0; i < registros; i++) {
        values[i] = new double[variaveis];
    }

    //Reading the data file
    for(int i = 0; i < registros; i++) {
        for(int j = 0; j < variaveis; j++) {
            inputFile >> values[i][j];
        }
    }

    inputFile.close();


}

double* Database::getRegister(int position) {
    return position < registros ? values[position] : NULL;
}

void Database::print() {
    for(int i = 0; i < registros; i++) {
        for(int j = 0; j < variaveis; j++)
            cout << values[i][j] << "\t";
        cout << endl;
    }
}

Database::~Database() {
    //dtor
}
