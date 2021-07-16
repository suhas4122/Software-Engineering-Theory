/*
    CS20006 Assignment 5
    Name.h
    By : Suhas Jain
    Roll No : 19CS30048
*/

// Header File for class Name

#ifndef __NAME_H
#define __NAME_H

#include "Exceptions.h"

#include <iostream>
#include <string>
using namespace std;

class Name {
private:
    const string firstName_;
    const string middleName_;
    const string lastName_;

public:
    Name(const string&, const string&, const string&);
    ~Name() {}
    static const Name* CreateName(const string&, const string&, const string&);
    friend ostream& operator<<(ostream&, const Name&);
    static void UnitTestName();

    friend class Passenger;
};

#endif //__NAME_H