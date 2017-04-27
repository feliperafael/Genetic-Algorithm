#include "SimpleMutation.h"

SimpleMutation::SimpleMutation()
{
    //ctor
}

void SimpleMutation::mutate(Individual * individuo){
    //receber diretamente um simpleIndividual??
    SimpleIndividual * s1 = dynamic_cast<SimpleIndividual*>(individuo);

}

SimpleMutation::~SimpleMutation()
{
    //dtor
}
