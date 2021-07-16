/*
    CS20006 Assignment 3
    BookingClasses.cpp
    Suhas Jain (19CS30048)
*/

// Including project header files
#include "BookingClasses.h"

BookingClasses::BookingClasses(const string& name, const bool isAC, const bool isLuxury) : name_(name), isAC_(isAC), isLuxury_(isLuxury)
{
    #if _DEBUG
        cout << "BookingClass Created\n";
    #endif // _DEBUG
}

BookingClasses::~BookingClasses()
{
    #if _DEBUG
        cout << "BookingClass Destroyed\n";
    #endif // _DEBUG
}

string BookingClasses::GetName() const
{
    return name_;
}

bool BookingClasses::IsAC() const
{
    return isAC_;
}

bool BookingClasses::IsLuxury() const
{
    return isLuxury_;
}

ostream& operator<<(ostream& os, const BookingClasses& x)
{
    string _name, _isSitting, _isAC, _isLuxury;
    int _noOfTiers;

    _name = x.GetName();
    if(x.IsSitting())
        _isSitting = "Sitting";
    else
        _isSitting = "Sleeping";
    if(x.IsAC())
        _isAC = "AC";
    else
        _isAC = "Non-AC";
    _noOfTiers = x.GetNumberOfTiers();
    _isLuxury = x.IsLuxury() ? "Yes" : "No";

    os << "Travel Class = " << _name << endl;
    os << " : Mode: " << _isSitting << endl;
    os << " : Comfort: " << _isAC << endl;
    os << " : Bunks: " << _noOfTiers << endl;
    os << " : Luxury: " << _isLuxury;
    
    return os;
}

Berth::Berth(const string& name, const bool isAC, const bool isLuxury) : BookingClasses(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "Berth Created\n";
    #endif // _DEBUG
}

Berth::~Berth()
{
    #if _DEBUG
        cout << "Berth Destroyed\n";
    #endif // _DEBUG
}

bool Berth::IsSitting() const
{
    return false;
}

Seat::Seat(const string& name, const bool isAC, const bool isLuxury) : BookingClasses(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "Seat Created\n";
    #endif // _DEBUG
}

Seat::~Seat()
{
    #if _DEBUG
        cout << "Seat Destroyed\n";
    #endif // _DEBUG
}

bool Seat::IsSitting() const
{
    return true;
}

int Seat::GetNumberOfTiers() const
{
    return 0;
}

Tiers2::Tiers2(const string& name, const bool isAC, const bool isLuxury) : Berth(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "Tiers2 Created\n";
    #endif // _DEBUG
}

Tiers2::~Tiers2()
{
    #if _DEBUG
        cout << "Tiers2 Destroyed\n";
    #endif // _DEBUG
}

int Tiers2::GetNumberOfTiers() const
{
    return 2;
}

Tiers3::Tiers3(const string& name, const bool isAC, const bool isLuxury) : Berth(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "Tiers3 Created\n";
    #endif // _DEBUG
}

Tiers3::~Tiers3()
{
    #if _DEBUG
        cout << "Tiers3 Destroyed\n";
    #endif // _DEBUG
}

int Tiers3::GetNumberOfTiers() const
{
    return 3;
}

// ACFirstClass

ACFirstClass::ACFirstClass(const string &name = "ACFirstClass", bool isAC = true, bool isLuxury = true) : Tiers2(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "ACFirstClass Created\n";
    #endif // _DEBUG
}

ACFirstClass::~ACFirstClass()
{
    #if _DEBUG
        cout << "ACFirstClass Destroyed\n";
    #endif // _DEBUG
}

const ACFirstClass& ACFirstClass::Type()
{
    const static ACFirstClass obj("AC First Class", true, true);
    return obj;
}

double ACFirstClass::GetLoadFactor() const
{
    return sLoadFactor;
}


// AC2Tier

AC2Tier::AC2Tier(const string &name = "AC 2 Tier", bool isAC = true, bool isLuxury = false) : Tiers2(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "AC2Tier Created\n";
    #endif // _DEBUG
}

AC2Tier::~AC2Tier()
{
    #if _DEBUG
        cout << "AC2Tier Destroyed\n";
    #endif // _DEBUG
}

const AC2Tier& AC2Tier::Type()
{
    static const AC2Tier theObj("AC 2 Tier", true, false);
    return theObj;
}

double AC2Tier::GetLoadFactor() const
{
    return sLoadFactor;
}


// FirstClass

FirstClass::FirstClass(const string &name = "First Class", bool isAC = false, bool isLuxury = true) : Tiers2(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "FirstClass Created\n";
    #endif // _DEBUG
}

FirstClass::~FirstClass()
{
    #if _DEBUG
        cout << "FirstClass Destroyed\n";
    #endif // _DEBUG
}

const FirstClass& FirstClass::Type()
{
    static const FirstClass theObj("First Class", false, true);
    return theObj;
}

double FirstClass::GetLoadFactor() const
{
    return sLoadFactor;
}


// AC3Tier

AC3Tier::AC3Tier(const string &name = "AC 3 Tier", bool isAC = true, bool isLuxury=false) : Tiers3(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "AC3Tier Created\n";
    #endif // _DEBUG
}

AC3Tier::~AC3Tier()
{
    #if _DEBUG
        cout << "AC3Tier Destroyed\n";
    #endif // _DEBUG
}

const AC3Tier& AC3Tier::Type()
{
    static const AC3Tier theObj("AC 3 Tier", true, false);
    return theObj;
}

double AC3Tier::GetLoadFactor() const
{
    return sLoadFactor;
}


// ACChairCar

ACChairCar::ACChairCar(const string &name = "AC Chair Car", bool isAC = true, bool isLuxury = false) : Seat(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "ACChairCar Created\n";
    #endif // _DEBUG
}

ACChairCar::~ACChairCar()
{
    #if _DEBUG
        cout << "ACChairCar Destroyed\n";
    #endif // _DEBUG
}

const ACChairCar& ACChairCar::Type()
{
    static const ACChairCar theObj("AC Chair Car", true, false);
    return theObj;
}

double ACChairCar::GetLoadFactor() const
{
    return sLoadFactor;
}


// Sleeper

Sleeper::Sleeper(const string &name = "Sleeper", bool isAC = false, bool isLuxury = false) : Tiers3(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "Sleeper Created\n";
    #endif // _DEBUG
}

Sleeper::~Sleeper()
{
    #if _DEBUG
        cout << "Sleeper Destroyed\n";
    #endif // _DEBUG
}

const Sleeper& Sleeper::Type()
{
    static const Sleeper theObj("Sleeper", false, false);
    return theObj;
}

double Sleeper::GetLoadFactor() const
{
    return sLoadFactor;
}


// SecondSitting

SecondSitting::SecondSitting(const string &name = "Second Sitting", bool isAC = false, bool isLuxury = false) : Seat(name, isAC, isLuxury)
{
    #if _DEBUG
        cout << "SecondSitting Created\n";
    #endif // _DEBUG
}

SecondSitting::~SecondSitting()
{
    #if _DEBUG
        cout << "SecondSitting Destroyed\n";
    #endif // _DEBUG
}

const SecondSitting& SecondSitting::Type()
{
    static const SecondSitting theObj("Second Sitting", false, false);
    return theObj;
}

double SecondSitting::GetLoadFactor() const
{
    return sLoadFactor;
}

// int main()
// {
//     cout << ACFirstClass::Type() << endl;
//     cout << AC2Tier::Type() << endl;
//     cout << FirstClass::Type() << endl;
//     cout << AC3Tier::Type() << endl;
//     cout << ACChairCar::Type() << endl;
//     cout << Sleeper::Type() << endl;
//     cout << SecondSitting::Type() << endl;
// }
