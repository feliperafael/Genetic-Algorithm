#include "SimpleParser.h"

SimpleParser::SimpleParser()
{
    //ctor
}

double SimpleParser::Evaluate(Individual* s){
    SimpleIndividual * s1 = dynamic_cast<SimpleIndividual*>(s);
    double erro = 0;
    for(int i = 0; i < 40; i++){
        erro += sqrt(pow( database->getRegister(i)[1] - s1->x,2));
    }
    for(int i = 0; i < 1000; i++){
        erro = (erro + erro)/2;
    }

    //cout << "erro : " << erro << endl;
    //cin.get();
    return (double)erro;

}

string SimpleParser::nameParser(){
    return "SimpleParser";
}
 void SimpleParser::setDatabase(Database * data){
    database = data;
 }
SimpleParser::~SimpleParser()
{
    //dtor
}
