/*
    CS20006 Assignment 3
    Passenger.h
    Suhas Jain (19CS30048)
*/

#ifndef __PASSENGER_H // Control inclusion of header files
#define __PASSENGER_H

// C++ Headers
#include <iostream>
#include <vector>
using namespace std;

// Class Declaration for the Passenger class
class Passenger
{
    protected:
        enum Gender {Male = 0, Female};
        const string name_;
        const string aadhaar_;
        const Date dateOfBirth_;
        const Gender gender_;
        string mobile_;
        const string category_;
};

#endif // __PASSENGER_H