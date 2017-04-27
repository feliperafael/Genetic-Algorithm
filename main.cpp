#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "SearchEngine.h"
#include "Configures.h"
using namespace std;

int main()
{
    conf = new Configures(); //Configuration class with several GA parameters
    SearchEngine * searcher = new SearchEngine();

    return 0;
}
