/*
    CS20006 Assignment 5
    Name.h
    By : Suhas Jain
    Roll No : 19CS30048
*/

// Header File for class Name
#include "Name.h"

//Constructor of the name class
Name::Name(const string& firstName, const string& middleName, const string& lastName) : firstName_(firstName), middleName_(middleName), lastName_(lastName)
{}

//Function that takes first, middle and last names as string and makes returs the object after checking for guidelines
//(Atleast 1 of first or last names should be present)
const Name* Name::CreateName(const string& firstName, const string& middleName, const string& lastName) {
    if(firstName == "" && middleName == "" && lastName == "")
        throw Invalid_Name("Name cannot be completely empty");
    else if(firstName == "" && lastName == "")
        throw Invalid_Name("At least one of first name or last name should be present");

    return new Name(firstName, middleName, lastName);
}

//Overloaded output streaming operator to print the name from the object  
ostream& operator<<(ostream& os, const Name& name) {
    os << name.firstName_ << (name.firstName_ != "" ? " " : "") << name.middleName_ << (name.middleName_ != "" ? " " : "") << name.lastName_;
    return os;
}