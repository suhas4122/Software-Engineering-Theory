/*
    CS20006 Assignment 3
    Station.cpp
    Suhas Jain (19CS30048)
*/

// Including project header files
#include "Station.h"
#include "Railways.h"

Station::Station(const string& name) : name_(name)
{
    #if _DEBUG
        cout << "Station Created\n";
    #endif // _DEBUG
}

Station::Station(const Station& s) : name_(s.name_)
{}

Station::~Station()
{
    #if _DEBUG
        cout << "Station Destroyed\n";
    #endif // _DEBUG
}

string Station::GetName() const
{
    return name_;
}

int Station::GetDistance(const Station& s) const
{
    return Railways::Type().GetDistance(*this, s);
}

ostream& operator<<(ostream& os, const Station& s)
{
    os << "Station : " << s.name_;
    return os;
}
