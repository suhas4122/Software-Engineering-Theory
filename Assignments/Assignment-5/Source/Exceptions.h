/*
    CS20006 Assignment 5
    Exceptions.h
    By : Suhas Jain
    Roll No : 19CS30048
*/

// Header File for class Exceptions

#ifndef __EXCEPTIONS_H
#define __EXCEPTIONS_H

#include <exception>
#include <iostream>
#include <string>
using namespace std;

//Making the base class of our exception hierarchy by inheriting from standard exception class
class Exceptions : public exception 
{
protected:
    const string message_;
public:
    Exceptions(const string&);
    virtual const char* what() const throw();
};




//Derived class to throw an exception in case of bad date 
//(In case date pointer allocation does not take place properly)
class Bad_Date : public Exceptions 
{
public:
    Bad_Date(const string&);
};

//Derived class to throw an exception in case of invalid date 
//(In case the date entered by the user does not meet the given guidelines)
class Invalid_Date : public Bad_Date 
{
public:
    Invalid_Date(const string&);
};

//Derived class from bad date to throw exception if a date is out of range
//(Before 1900 or after 2050)
class Date_Out_Of_Range : public Bad_Date 
{
public:
    Date_Out_Of_Range(const string&);
};



//Throws exception if a string which does not match any station is passed
class Bad_Station : public Exceptions 
{
public:
    Bad_Station(const string&);
};




//Throws exception in case of wrong data in railways class
class Bad_Railways : public Exceptions 
{
public:
    Bad_Railways(const string&);
};

//Throws exception in case a station is present more than once in list of stations
class Duplicate_Station: public Bad_Railways 
{
public:
    Duplicate_Station(const string&);
};

//Throws exception in case diatnce data for a pair of stations is present more than once
class Duplicate_Pair: public Bad_Railways 
{
public:
    Duplicate_Pair(const string&);
};




//Throws exception in case of wrong data in passenger class
class Bad_Passenger : public Exceptions 
{
public:
    Bad_Passenger(const string&);
};

//Throws exception in case of wrong name format according to guidelines in railways class
class Invalid_Name : public Bad_Passenger 
{
public:
    Invalid_Name(const string&);
};

//Throws exception in case of wrong date of birth format according to guidelines in railways class
class Wrong_DOB : public Bad_Passenger 
{
public:
    Wrong_DOB(const string&);
};

//Throws exception in case of wrong aahaar information according to guidelines in railways class
class Wrong_Aadhaar : public Bad_Passenger 
{
public:
    Wrong_Aadhaar(const string&);
};

//Throws exception in case of wrong mobile number format according to guidelines in railways class
class Wrong_Mobile : public Bad_Passenger 
{
public:
    Wrong_Mobile(const string&);
};



//Throws exception in case of wrong data in booking class
class Bad_Booking : public Exceptions 
{
public:
    Bad_Booking(const string&);
};

//Throws exception in case source and destination stations are the same
class Same_Stations : public Bad_Booking 
{
public:
    Same_Stations(const string&);
};

//Throws exception in case of the pair of booking date and reservation date does not meet guidelines 
class Invalid_Booking_Date : public Bad_Booking 
{
public:
    Invalid_Booking_Date(const string&);
};

#endif // __EXCEPTIONS_H