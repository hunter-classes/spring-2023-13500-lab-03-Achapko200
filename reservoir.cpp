#include "reservoir.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void split(const std::string &s, char delim, std::vector<std::string> &elems)
{
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim))
    {
        elems.push_back(item);
    }
}

double get_east_storage(std::string date)
{
    std::ifstream datafile("Current_Reservoir_Levels.tsv");
    if (!datafile)
    {
        std::cerr << "Error opening data file" << std::endl;
        return -1;
    }
    std::string line, junk;
    std::getline(datafile, line);
    double east_storage = -1;
    while (std::getline(datafile, line))
    {
        std::vector<std::string> fields;
        split(line, '\t', fields);

        std::string date_in_file = fields[0];
        double east_storage_in_file = std::stod(fields[2]);

        if (date == date_in_file)
        {
            east_storage = east_storage_in_file;
            break;
        }
    }
    datafile.close();

    return east_storage;
}

double get_min_east()
{
    std::string date;
    double eastSt, eastEl, westSt, westEl, min, max;
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail())
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);
    int i = 0;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MIN, '\n');
        if (i == 0)
        {
            min = eastSt;
        }
        if (min > eastSt)
            min = eastSt;
        i++;
    }
    fin.close();
    return min;
}
double get_max_east()
{
    std::string date;
    double eastSt, eastEl, westSt, westEl, min, max;
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail())
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);
    int i = 0;
    while (fin >> date >> eastSt >> eastEl >> westSt >> westEl)
    {
        fin.ignore(INT_MAX, '\n');
        if (i == 0)
        {
            max = eastSt;
        }
        if (max < eastSt)
            max = eastSt;
        i++;
    }

    fin.close();
    return max;
}
std::string compare_basins(std::string date)
{
    std::string dates;

    double eastSt, eastEl, westSt, westEl, min, max;
    std::ifstream fin("Current_Reservoir_Levels.tsv");
    if (fin.fail())
    {
        std::cerr << "File cannot be opened for reading." << std::endl;
        exit(1);
    }
    std::string junk;
    getline(fin, junk);
    int i = 0;
    while (fin >> dates >> eastSt >> eastEl >> westSt >> westEl)
    {
        if (date.compare(dates) == 0)
        {
            if (eastSt > westSt)
            {
                return "East";
            }
            if (eastSt < westSt)
            {
                return "West";
            }
            if (eastSt = westSt)
            {
                return "equal";
            }
        }
    }
}