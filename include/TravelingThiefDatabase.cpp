#include "TravelingThiefDatabase.h"

TravelingThiefDatabase::TravelingThiefDatabase()
{
    //ctor
}


void TravelingThiefDatabase::loadBase(string base_name)
{
    ifstream inputFile;

    inputFile.open(base_name.c_str());

    if(!inputFile.is_open())
    {
        cout << "Impossible to open input file, check file path : " << base_name.c_str() << endl;
        exit(1);
    }
    else
    {
        #ifdef debug
                cout << base_name << " is opened" << endl;
        #endif
    }

    //data array instance
    values = new double*[registros];
    for(int i = 0; i < registros; i++)
    {
        values[i] = new double[variaveis];
    }

    //Reading header
    string line = "";
    vector<string> line_vec;

    getline(inputFile, line);
    line_vec = explode(line,':');

    PROBLEM_NAME = remove_space(line_vec[1]);

    line_vec.erase(line_vec.begin(),line_vec.end());

    getline(inputFile, line);
    line_vec = explode(line,':');
    KNAPSACK_DATA_TYPE = line_vec[1];

    line_vec.erase(line_vec.begin(),line_vec.end());

    inputFile >> line >> DIMENSION;

    inputFile >> line >> line >> line >> NUMBER_OF_ITEMS;

    inputFile>> line >> line >> line >> CAPACITY_OF_KNAPSACK;

    inputFile >> line  >> line >> MIN_SPEED;

    inputFile >> line  >> line >> MAX_SPEED;

    inputFile >> line  >> line >> RENTING_RATIO;

    inputFile >> line >> EDGE_WEIGHT_TYPE;

    inputFile >> line  >> line >> line >> line;


    conf->DIMENSION = DIMENSION;
    conf->NUMBER_OF_ITEMS = NUMBER_OF_ITEMS;
    conf->CAPACITY_OF_KNAPSACK = CAPACITY_OF_KNAPSACK;
    conf->MIN_SPEED = MIN_SPEED;
    conf->MAX_SPEED = MAX_SPEED;
    conf->RENTING_RATIO = RENTING_RATIO;
//    printInstanceHeader();

    int index,x,y;

    City* city;
    //reader citys
    for(int i = 0; i < DIMENSION; ++i){
        inputFile >> index >> x  >> y;
        city = new City();
        city->setObject(index - 1, x, y);
        cities.push_back(city);
    }

    inputFile >> line  >> line >> line >> line >> line >> line >> line >> line;

    int INDEX, PROFIT, WEIGHT, ASSIGNED_NODE_NUMBER;
    Item* item;

    //reader itens
    for(int i = 0; i < NUMBER_OF_ITEMS; ++i){
        inputFile >> INDEX >> PROFIT >> WEIGHT >> ASSIGNED_NODE_NUMBER;
        item = new Item();
        item->setObject(INDEX - 1, PROFIT, WEIGHT, ASSIGNED_NODE_NUMBER - 1);
        cities.at(ASSIGNED_NODE_NUMBER - 1)->addItem(item);
    }

    //cout << cities.size() << endl;

//    for(City * city : cities)
//        city->print();


    inputFile.close();

}


void TravelingThiefDatabase::printInstanceHeader(){

    cout << "PROBLEM_NAME :\t\t\t" << PROBLEM_NAME << endl;
    cout << "KNAPSACK_DATA_TYPE :\t\t" << KNAPSACK_DATA_TYPE << endl;
    cout << "DIMENSION :\t\t\t" << DIMENSION << endl;
    cout << "NUMBER_OF_ITEMS :\t\t" << NUMBER_OF_ITEMS << endl;
    cout << "CAPACITY_OF_KNAPSACK :\t\t" << CAPACITY_OF_KNAPSACK << endl;
    cout << "MIN_SPEED :\t\t\t" << MIN_SPEED << endl;
    cout << "MAX_SPEED :\t\t\t" << MAX_SPEED << endl;
    cout << "RENTING_RATIO :\t\t\t" << RENTING_RATIO << endl;
    cout << "EDGE_WEIGHT_TYPE :\t\t" << EDGE_WEIGHT_TYPE << endl;
    cout << endl;

}

const vector<string> TravelingThiefDatabase::explode(const string& s, const char& c)
{
    string buff = "";
    vector<string> v;

    for(n:s)
    {
        if(n != c) buff+=n;
        else if(n == c && buff != "")
        {
            v.push_back(buff);
            buff = "";
        }
    }
    if(buff != "") v.push_back(buff);

    return v;
}

string TravelingThiefDatabase::remove_space(string input){input.erase(remove_if(input.begin(), input.end(), ::isspace),input.end()); return input;}


TravelingThiefDatabase::~TravelingThiefDatabase()
{
    //dtor
}
