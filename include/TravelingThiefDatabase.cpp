#include "TravelingThiefDatabase.h"

TravelingThiefDatabase::TravelingThiefDatabase()
{
    //ctor
}


void TravelingThiefDatabase::loadBase(string base_name)
{
    ifstream inputFile;

    inputFile.open(base_name.c_str());

    this->variaveis = 2;
    this->registros = 40;

    if(!inputFile.is_open())
    {
        cout << "Impossible to open input file, check file path : " << base_name.c_str() << endl;
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

//    printInstanceHeader();

    int index,x,y;

    for(int i = 0; i < DIMENSION; ++i){
//        getline(inputFile, line);
//        cout << line << endl;
        inputFile >> index >> x  >> y;
        //cout << i << " " << index << " " << x << " " << y << endl << endl << endl;
    }

    inputFile >> line  >> line >> line >> line >> line >> line >> line >> line;


    int INDEX, PROFIT, WEIGHT, ASSIGNED_NODE_NUMBER;

    for(int i = 0; i < NUMBER_OF_ITEMS; ++i){
        inputFile >> INDEX >> PROFIT >> WEIGHT >> ASSIGNED_NODE_NUMBER;
        //cout << INDEX << " " << PROFIT << " " << WEIGHT << " " << ASSIGNED_NODE_NUMBER << endl;
    }

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
