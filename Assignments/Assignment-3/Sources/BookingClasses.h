/*
    CS20006 Assignment 3
    BookingClasses.h
    Suhas Jain (19CS30048)
*/

#ifndef __BOOKINGCLASSES_H // Control inclusion of header files
#define __BOOKINGCLASSES_H

// C++ Headers
#include <iostream>
using namespace std;

// Abstract Base Class
class BookingClasses
{
protected:
    // Data members to be present in each concrete child class
    const string name_;
    const bool isAC_;
    const bool isLuxury_;

    BookingClasses(const string&, const bool, const bool);
    virtual ~BookingClasses();

public:
    virtual double GetLoadFactor() const = 0;
    string GetName() const;
    virtual bool IsSitting() const = 0;
    bool IsAC() const;
    virtual int GetNumberOfTiers() const = 0;
    bool IsLuxury() const;

    friend ostream& operator<<(ostream&, const BookingClasses&); // Output streaming operator
};

// Abstract Class
class Berth: public BookingClasses
{  
protected:
    Berth(const string&, const bool, const bool);
    ~Berth();

public:
    virtual bool IsSitting() const; 
};

// Abstract Class
class Seat: public BookingClasses
{
protected:
    Seat(const string&, const bool, const bool);
    ~Seat();

public:
    virtual bool IsSitting() const;
    virtual int GetNumberOfTiers() const;
};

// Abstract Class
class Tiers2: public Berth
{
protected:
    Tiers2(const string&, const bool, const bool);
    ~Tiers2();

public:
    virtual int GetNumberOfTiers() const;
};

// Abstract Class
class Tiers3: public Berth
{
protected:
    Tiers3(const string&, const bool, const bool);
    ~Tiers3();
    
public:
    virtual int GetNumberOfTiers() const;
};

// Concrete Class Declarations

class ACFirstClass: public Tiers2
{
private:
    ACFirstClass(const string &name, bool isAC, bool isLuxury);
    ~ACFirstClass();

    ACFirstClass(const ACFirstClass&);
    ACFirstClass& operator=(const ACFirstClass&);

public:
    static const double sLoadFactor;
    static const ACFirstClass& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestACFirstClass();
};

class AC2Tier: public Tiers2
{
private:
    AC2Tier(const string &name, bool isAC, bool isLuxury);
    ~AC2Tier();

    AC2Tier(const AC2Tier&);
    AC2Tier& operator=(const AC2Tier&);

public:
    static const double sLoadFactor;
    static const AC2Tier& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestAC2Tier();
};

class FirstClass: public Tiers2
{
private:
    FirstClass(const string &name, bool isAC, bool isLuxury);
    ~FirstClass();

    FirstClass(const FirstClass&);
    FirstClass& operator=(const FirstClass&);

public:
    static const double sLoadFactor;
    static const FirstClass& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestFirstClass();
};

class AC3Tier: public Tiers3
{
private:
    AC3Tier(const string &name, bool isAC, bool isLuxury);
    ~AC3Tier();

    AC3Tier(const AC3Tier&);
    AC3Tier& operator=(const AC3Tier&);

public:
    static const double sLoadFactor;
    static const AC3Tier& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestAC3Tier();
};

class ACChairCar: public Seat
{
private:
    ACChairCar(const string &name, bool isAC, bool isLuxury);
    ~ACChairCar();

    ACChairCar(const ACChairCar&);
    ACChairCar& operator=(const ACChairCar&);

public:
    static const double sLoadFactor;
    static const ACChairCar& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestACChairCar();
};

class Sleeper: public Tiers3
{
private:
    Sleeper(const string &name, bool isAC, bool isLuxury);
    ~Sleeper();

    Sleeper(const Sleeper&);
    Sleeper& operator=(const Sleeper&);

public:
    static const double sLoadFactor;
    static const Sleeper& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestSleeper();
};

class SecondSitting: public Seat
{
private:
    SecondSitting(const string &name, bool isAC, bool isLuxury);
    ~SecondSitting();

    SecondSitting(const SecondSitting&);
    SecondSitting& operator=(const SecondSitting&);

public:
    static const double sLoadFactor;
    static const SecondSitting& Type();
    virtual double GetLoadFactor() const;
    static void UnitTestSecondSitting();
};

#endif // __BOOKINGCLASSES_H