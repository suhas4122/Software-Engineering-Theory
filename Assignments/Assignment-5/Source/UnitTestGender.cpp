/*
    CS20006 Assignment 5
    UnitTestGender.cpp
    By : Suhas Jain
        Roll No : 19CS30048
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Gender.cpp UnitTestGender.cpp -o test
    ./test
*/

// Unit Testing File for class Gender

// Including project header files
#include "Gender.h"

// C++ Headers
#include <cassert>
#include <sstream>
#include <iostream>

void Gender::UnitTestGender() {
    // Testing the Male class

    //Testing the singleton behavior of the class
    const Gender::Male* firstPointer = &Gender::Male::Type();
    const Gender::Male* secondPointer = &Gender::Male::Type();
    assert(firstPointer == secondPointer);

    const Gender::Male& maleObj = Gender::Male::Type();

    //Testing GetName function
    assert("Male" == maleObj.GetName());

    //Testing GetTitle function
    assert("Mr." == maleObj.GetTitle());

    //Testing the IsMale function for male class
    assert(true == Gender::IsMale(maleObj));

    stringstream out;
    //Checking the output streaming operator
    out << maleObj;
    assert("Male" == out.str());

    cout << maleObj << endl;


    // Testing the Female class
    //Testing the singleton behavior of the class
    const Gender::Female* firstPointer1 = &Gender::Female::Type();
    const Gender::Female* secondPointer1 = &Gender::Female::Type();
    assert(firstPointer1 == secondPointer1);

    const Gender::Female& femaleObj = Gender::Female::Type();

    //Testing GetName function
    assert("Female" == femaleObj.GetName());

    //Testing GetTitle function
    assert("Ms." == femaleObj.GetTitle());

    ////Testing the IsMale function for female class
    assert(false == Gender::IsMale(femaleObj));

    out.str("");
    out << femaleObj;
    assert("Female" == out.str());

    cout << femaleObj << endl;
}

int main() {
    Gender::UnitTestGender();
    return 0;
}