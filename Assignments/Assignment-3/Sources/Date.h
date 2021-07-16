/*
    CS20006 Assignment 3
    Date.h
    Suhas Jain (19CS30048)
*/

#ifndef __DATE_H // Control inclusion of header files
#define __DATE_H

// C++ Headers
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;



// Class Declaration for the Date class
class Date
{
private:
    // Enum declarations
    enum Month {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
    enum Day {Sat, Sun, Mon, Tue, Wed, Thr, Fri};
    static const vector<string> sMonthNames; // List of month names
    static const vector<string> sDayNames; // List of day names
    const int date_; // date variable
    const Month month_; // month variable
    const int year_; // year variable

    Date& operator=(const Date&); // Blocked copy assignment operator
    
public:
    Date(int d = 1, int m = 1, int y = 2021); // Constructor
    Date(const Date&); // Copy Constructor
    ~Date(); // Destructor
    Day day() const; // Function to get day from date
    inline bool operator==(const Date& d) //inline assignment
    {
        return (date_==d.date_ && month_==d.month_ && year_==d.year_);
    }
    friend ostream& operator<<(ostream&, const Date&); // Output Streaming Operator
    static void UnitTestDate(); // Static function for unit testing
};

#endif // __DATE_H