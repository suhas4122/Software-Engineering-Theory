/*
    CS20006 Assignment 3
    Railways.cpp
    Suhas Jain (19CS30048)
*/

// Including project header files
#include "Railways.h"

// Initializing the static constants
const vector<Station> Railways::sStations = {Station("Mumbai"), Station("Delhi"), Station("Bangalore"), Station("Kolkata"), Station("Chennai")};

const map<pair<string, string>, int> Railways::sDistStations = {{{"Mumbai", "Delhi"}, 1447}, {{"Delhi", "Mumbai"}, 1447}, {{"Mumbai", "Bangalore"}, 981}, {{"Bangalore", "Mumbai"}, 981}, 
    {{"Mumbai", "Kolkata"}, 2014}, {{"Kolkata", "Mumbai"}, 2014}, {{"Mumbai", "Chennai"}, 1338}, {{"Chennai", "Mumbai"}, 1338}, {{"Delhi", "Bangalore"}, 2150}, {{"Bangalore", "Delhi"}, 2150},
    {{"Delhi", "Kolkata"}, 1472}, {{"Kolkata", "Delhi"}, 1472}, {{"Delhi", "Chennai"}, 2180}, {{"Chennai", "Delhi"}, 2180}, {{"Bangalore", "Kolkata"}, 1871}, {{"Kolkata", "Bangalore"}, 1871},
    {{"Bangalore", "Chennai"}, 350}, {{"Chennai", "Bangalore"}, 350}, {{"Kolkata", "Chennai"}, 1659}, {{"Chennai", "Kolkata"}, 1659}};

Railways::Railways()
{
    #if _DEBUG
        cout << "Railways Created\n";
    #endif // _DEBUG
}

Railways::~Railways()
{
    #if _DEBUG
        cout << "Railways Destroyed\n";
    #endif // _DEBUG
}

const Railways& Railways::Type()
{
    static const Railways theObj;
    return theObj; 
}

int Railways::GetDistance(const Station& fromStation, const Station& toStation) 
{
    return Railways::sDistStations.at({fromStation.GetName(), toStation.GetName()});
}

ostream& operator<<(ostream& os, const Railways& IndianRailways)
{
    // Here we print all the stations and the pairwise distances between the stations
    os << "Indian Railways\n\n";
    os << "List of Stations\n";
    vector<Station>::const_iterator it;
    for(it = Railways::sStations.begin(); it != Railways::sStations.end(); it++)
    {
        os << (*it) <<"\n";
    }
    os << "\nPairwise Distances\n";
    set<pair<string, string>> occured;
    map<pair<string, string>, int>::const_iterator iter;
    for(iter = Railways::sDistStations.begin(); iter != Railways::sDistStations.end(); iter++)
    {
        pair<string, string> s = iter->first;
        if(!occured.count(s))
        {
            os << s.first << " - " << s.second << " = " << iter -> second << " km\n";
            occured.insert(s);
        }
    }
    return os;
}
