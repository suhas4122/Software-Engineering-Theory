/*
    CS20006 Assignment 3
    UnitTestDate.cpp
    Suhas Jain (19CS30048)
*/

#include <iostream>
#include <cassert>
#include <sstream>
#include "Date.h"
using namespace std;

enum Month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
enum Day {Sun, Mon, Tue, Wed, Thr, Fri, Sat};

void Date::UnitTestDate()
{
    Date d(7, 3, 2021); // Constructor called, with 7, 3 and 2021 as parametrs
    Date d1(d); // Copy constructor called
    Date d2 = d1; // Copy constructor called

    Date d3; // Constructor called
    Date d4(5); // Constructor called
    Date d5(5, 6);

    Date d6(7, 3, 2020);
    Date d7(7, 4, 2021);
    Date d8(8, 3, 2021);
    Date d9(8, 4, 2020);
    
    assert(7==d.date_ && Mar==d.month_ && 2021==d.year_);
    assert(1 == d.day());
    assert(7==d1.date_ && Mar==d1.month_ && 2021==d1.year_);
    assert(1 == d1.day());
    assert(7==d2.date_ && Mar==d2.month_ && 2021==d2.year_);
    assert(1 == d2.day());
    assert(1==d3.date_ && Jan==d3.month_ && 2021==d3.year_);
    assert(6 == d3.day());
    assert(5==d4.date_ && Jan==d4.month_ && 2021==d4.year_);
    assert(3 == d4.day());
    assert(5==d5.date_ && Jun==d5.month_ && 2021==d5.year_);
    assert(0 == d5.day());

    assert(true == (d==d1));
    assert(true == (d1==d2));
    assert(false == (d==d6));
    assert(false == (d==d7));
    assert(false == (d==d8));
    assert(false == (d6==d7));
    assert(false == (d6==d8));
    assert(false == (d7==d8));
    assert(false == (d==d9));

    string expOut = "Sun, 7/Mar/2021\n";
    stringstream out;
    out << d;
    assert(expOut==out.str());
}

int main()
{
    Date::UnitTestDate();
    return 0;
}
