/*
    CS20006 Assignment 5
    UnitTestName.cpp
    By : Suhas Jain
    Roll No : 19CS30048
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Name.cpp Exceptions.cpp UnitTestName.cpp -o test
    ./test
*/

// Unit Testing File for the Name class
// Including project header files
#include "Name.h"
#include "Exceptions.h"

// C++ Headers
#include <cassert>
#include <sstream>

void Name::UnitTestName() {

    /*
    * POSITIVE TEST CASES
    */

    const Name n1("Daaku", "Mangal", "Singh");
    assert("Daaku" == n1.firstName_ && "Mangal" == n1.middleName_ && "Singh" == n1.lastName_);

    try {
        const Name* np1 = Name::CreateName("Daaku", "Mangal", "Singh");
        assert("Daaku" == np1 -> firstName_ && "Mangal" == np1 -> middleName_ && "Singh" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("Daaku", "", "Singh");
        assert("Daaku" == np1 -> firstName_ && "" == np1 -> middleName_ && "Singh" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("", "", "Singh");
        assert("" == np1 -> firstName_ && "" == np1 -> middleName_ && "Singh" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("Daaku", "", "");
        assert("Daaku" == np1 -> firstName_ && "" == np1 -> middleName_ && "" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("Daaku", "Mangal", "");
        assert("Daaku" == np1 -> firstName_ && "Mangal" == np1 -> middleName_ && "" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("", "Mangal", "Singh");
        assert("" == np1 -> firstName_ && "Mangal" == np1 -> middleName_ && "Singh" == np1 -> lastName_);
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    stringstream out;
    out << n1;

    string expectedOutput = "Daaku Mangal Singh";
    assert(expectedOutput == out.str());


    /*
    * NEGATIVE TEST CASES
    */

    try {
        const Name* np1 = Name::CreateName("", "", "");
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }

    try {
        const Name* np1 = Name::CreateName("", "Mangal", "");
    } catch(Invalid_Name& e) {
        cout << e.what() << endl;
    }
}

int main() {
    Name::UnitTestName();

    return 0;
}