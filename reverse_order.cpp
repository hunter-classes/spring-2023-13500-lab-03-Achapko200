#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include <sstream>
#include <vector>
#include "reverse_order.h"
using namespace std;
void reverse_order(std::string date1, std::string date2)
{

    ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail())
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    vector<string> Date;
    vector<float> westElVec;
    string header;
    getline(fin, header);
    string dateArr[365], date;
    double eastSt, eastEl, westSt, westEl;



    int count = 0;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n');

        if (date>=date1 && date<=date2)
        {
            Date.push_back(date);
            westElVec.push_back(westEl);
            count++;
        }
    }

    for (int i = count; i >= 0; i--)
    {
        cout << Date[i];
        cout << westElVec[i];
    }
}