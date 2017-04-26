#include <iostream>
#include "SearchEngine.h"
#include "Configures.h"
using namespace std;

int main()
{
    Configures * conf = new Configures(); //Configuration class with several GA parameters
    SearchEngine * searcher = new SearchEngine();

    return 0;
}
