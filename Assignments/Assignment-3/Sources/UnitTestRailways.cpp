/*
    CS20006 Assignment 3
    UnitTestRailways.cpp
    Suhas Jain (19CS30048)
*/

#include <iostream>
#include <cassert>
#include <sstream>
#include "Railways.h"
using namespace std;

void Railways::UnitTestRailways()
{
    const Railways& i = Railways::Type();
    assert(&i == &Railways::Type());
    assert(1447 == GetDistance(Station("Mumbai"), Station("Delhi")));
    assert(2014 == GetDistance(Station("Mumbai"), Station("Kolkata")));
    assert(981 == GetDistance(Station("Mumbai"), Station("Bangalore")));
    assert(1338 == GetDistance(Station("Mumbai"), Station("Chennai")));
    assert(1472 == GetDistance(Station("Delhi"), Station("Kolkata")));
    assert(2150 == GetDistance(Station("Delhi"), Station("Bangalore")));
    assert(2180 == GetDistance(Station("Delhi"), Station("Chennai")));
    assert(1871 == GetDistance(Station("Kolkata"), Station("Bangalore")));
    assert(1659 == GetDistance(Station("Kolkata"), Station("Chennai")));
    assert(350 == GetDistance(Station("Bangalore"), Station("Chennai")));

    string expOut = "Indian Railways\n\nList of Stations\nStation : Mumbai\nStation : Delhi\nStation : Bangalore\nStation : Kolkata\nStation : "
                    "Chennai\n\nPairwise Distances\nBangalore - Chennai = 350 km\nBangalore - Delhi = 2150 km\nBangalore - Kolkata = 1871 km\n"
                    "Bangalore - Mumbai = 981 km\nChennai - Bangalore = 350 km\nChennai - Delhi = 2180 km\nChennai - Kolkata = 1659 km\nChennai"
                    " - Mumbai = 1338 km\nDelhi - Bangalore = 2150 km\nDelhi - Chennai = 2180 km\nDelhi - Kolkata = 1472 km\nDelhi - Mumbai = 1447 km\n"
                    "Kolkata - Bangalore = 1871 km\nKolkata - Chennai = 1659 km\nKolkata - Delhi = 1472 km\nKolkata - Mumbai = 2014 km\nMumbai - Bangalore"
                    " = 981 km\nMumbai - Chennai = 1338 km\nMumbai - Delhi = 1447 km\nMumbai - Kolkata = 2014 km\n";
    stringstream out;
    out << i;
    cout<< i;
    assert(expOut==out.str());
}

int main()
{
    Railways::UnitTestRailways();
    return 0;
}
