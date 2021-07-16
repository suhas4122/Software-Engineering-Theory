/*
    CS20006 Assignment 5
    Gender.cpp
    By : Suhas Jain
    Roll No : 19CS30048
*/

// Source File for class Gender

#include "Gender.h"

using namespace std;

// Names defined as static constants
template<> const string Gender::Male::sName = "Male";
template<> const string Gender::Female::sName = "Female";

// Salutations defined as static constants
template<> const string Gender::Male::sSalutation = "Mr.";
template<> const string Gender::Female::sSalutation = "Ms.";

//Overloaded output streaming operator that prints the name of the gender
ostream& operator<<(ostream& os, const Gender& g)
{
    os << g.GetName();
    return os;
}