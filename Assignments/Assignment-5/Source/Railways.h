/*
    CS20006 Assignment 5
    Railways.h
    By : Suhas Jain
    Roll No : 19CS30048
*/

// Header File for class Railway

#ifndef __RAILWAYS_H // Control inclusion of header files
#define __RAILWAYS_H

// Project Headers
#include "Station.h"
#include "Exceptions.h"

// C++ Headers
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

// Class Declaration for the Railways class
// This is a singleton class

class Railways {
private:
    static const vector<const Station*> sStations; // List of all stations
    static const map<pair<string, string>, int> sDistStations; // Map to store pairwise distances betwen stations
    Railways() {} // Constructor
    ~Railways() {} // Destructor

    Railways(const Railways&); // Blocked copy constructor
    Railways& operator=(const Railways&); // Blocked copy assignment operator
    
public:
    static const Railways& IndianRailways(); // Function to return the single instance of the class
    int GetDistance(const Station&, const Station&) const; // Function to get the distance between any two stations
    const Station* GetStation(const string&) const; 
    friend ostream& operator<<(ostream&, const Railways&); // Output streaming operator
    static void UnitTestRailways(); // Static function for unit testing
};

#endif // __RAILWAYS_H