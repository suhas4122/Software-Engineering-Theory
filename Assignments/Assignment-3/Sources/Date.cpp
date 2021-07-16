/*
    CS20006 Assignment 3
    Date.cpp
    Suhas Jain (19CS30048)
*/

// Including project header files
#include "Date.h"
#include <cmath> 
using namespace std;

Date::Date(int d, int m, int y) : date_(d), month_(static_cast<Month>(m)), year_(y)
{
    #if _DEBUG
        cout << "Date Created\n";
    #endif // _DEBUG
}

Date::Date(const Date& d) : date_(d.date_), month_(d.month_), year_(d.year_)
{

}

Date::~Date()
{
    #if _DEBUG
        cout << "Date Destroyed\n";
    #endif // _DEBUG
}

Date::Day Date::day() const
{
    // Get the day of the week using the ctime library
    int mon;
    int year = year_;
    if(month_ > 2)
        mon = month_; //for march to december month code is same as month
    else{
        mon = (12+month_); //for Jan and Feb, month code will be 13 and 14
        year--; //decrease year for month Jan and Feb
    }
    int y = year % 100; //last two digit
    int c = year / 100; //first two digit
    int w = (date_ + floor((13*(mon+1))/5) + y + floor(y/4) + floor(c/4) + (5*c));
    w = w % 7;
    return static_cast<Date::Day>(w);
}

// Initializing the static variables
const vector<string> Date::sMonthNames = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
const vector<string> Date::sDayNames = {"Sat", "Sun", "Mon", "Tue", "Wed", "Thu", "Fri"};

ostream& operator<<(ostream& os, const Date& d)
{
    os << Date::sDayNames[d.day()];
    os << ", " << d.date_;
    os << "/" << Date::sMonthNames[d.month_ - 1];
    os << "/" << d.year_<<  endl;
    return os;
}

// int main()
// {
//     cout<<Date(04, 12, 2000);
// }