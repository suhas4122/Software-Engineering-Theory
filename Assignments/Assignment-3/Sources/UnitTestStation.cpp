/*
    CS20006 Assignment 3
    UnitTestStation.cpp
    Suhas Jain (19CS30048)
*/

#include <iostream>
#include <cassert>
#include <sstream>
#include "Station.h"
using namespace std;

void Station::UnitTestStation()
{
    Station s1("Mumbai");
    Station s2 = s1;
    Station s3("Chennai");
    Station s4("Kolkata");
    assert("Mumbai"==s1.name_);    
    assert("Mumbai"==s2.name_);    
    assert("Chennai"==s3.name_);    
    assert("Kolkata"==s4.name_);    
    assert(1338==s1.GetDistance(s3));
    assert(2014==s1.GetDistance(s4));

    string expOut = "Station : Kolkata"; 
    stringstream out;
    out << s4;
    assert(expOut==out.str());
}

int main()
{
    Station::UnitTestStation();
    return 0;
}
