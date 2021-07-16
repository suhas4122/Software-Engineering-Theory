/*
    CS20006 Assignment 3
    UnitTestBookingClasses.cpp
    Suhas Jain (19CS30048)
*/

#include <iostream>
#include <cassert>
#include <sstream>
#include "Booking.h"
using namespace std;

const double Booking::sBaseFarePerKM = 0.50;
const int Booking::sACSurcharge = 50;
const int Booking::sLuxuryTaxPercent = 25;

const double ACFirstClass::sLoadFactor = 3.00;
const double AC2Tier::sLoadFactor = 2.00;
const double FirstClass::sLoadFactor = 2.00;
const double AC3Tier::sLoadFactor = 1.75;
const double ACChairCar::sLoadFactor = 1.25;
const double Sleeper::sLoadFactor = 1.00;
const double SecondSitting::sLoadFactor = 0.5;

void ACFirstClass::UnitTestACFirstClass()
{
    const ACFirstClass &i = ACFirstClass::Type();
    assert(&i == &ACFirstClass::Type());

    assert(false==ACFirstClass::Type().IsSitting());
    assert(true==ACFirstClass::Type().isAC_);
    assert(true==ACFirstClass::Type().isLuxury_);

    assert(2==ACFirstClass::Type().GetNumberOfTiers());
    assert("AC First Class"==ACFirstClass::Type().GetName());
    assert(3.0==ACFirstClass::Type().GetLoadFactor());

    string expOut = "Travel Class = AC First Class\n : Mode: Sleeping\n : Comfort: AC\n : Bunks: 2\n : Luxury: Yes";
    stringstream out;
    out << ACFirstClass::Type();
    assert(expOut==out.str());
}

void AC2Tier::UnitTestAC2Tier()
{
    const AC2Tier &i = AC2Tier::Type();
    assert(&i == &AC2Tier::Type());
    
    assert(false==AC2Tier::Type().IsSitting());
    assert(true==AC2Tier::Type().isAC_);
    assert(false==AC2Tier::Type().isLuxury_);

    assert(2==AC2Tier::Type().GetNumberOfTiers());
    assert("AC 2 Tier"==AC2Tier::Type().GetName());
    assert(2.0==AC2Tier::Type().GetLoadFactor());

    string expOut = "Travel Class = AC 2 Tier\n : Mode: Sleeping\n : Comfort: AC\n : Bunks: 2\n : Luxury: No";
    stringstream out;
    out << AC2Tier::Type();
    assert(expOut==out.str());
}

void FirstClass::UnitTestFirstClass()
{
    const FirstClass &i = FirstClass::Type();
    assert(&i == &FirstClass::Type());

    assert(false==FirstClass::Type().IsSitting());
    assert(false==FirstClass::Type().isAC_);
    assert(true==FirstClass::Type().isLuxury_);

    assert(2==FirstClass::Type().GetNumberOfTiers());
    assert("First Class"==FirstClass::Type().GetName());
    assert(2.0==FirstClass::Type().GetLoadFactor());
    
    string expOut = "Travel Class = First Class\n : Mode: Sleeping\n : Comfort: Non-AC\n : Bunks: 2\n : Luxury: Yes";
    stringstream out;
    out << FirstClass::Type();
    assert(expOut==out.str());
}

void AC3Tier::UnitTestAC3Tier()
{
    const AC3Tier &i = AC3Tier::Type();
    assert(&i == &AC3Tier::Type());

    assert(false==AC3Tier::Type().IsSitting());
    assert(true==AC3Tier::Type().isAC_);
    assert(false==AC3Tier::Type().isLuxury_);

    assert(3==AC3Tier::Type().GetNumberOfTiers());
    assert("AC 3 Tier"==AC3Tier::Type().GetName());
    assert(1.75==AC3Tier::Type().GetLoadFactor());

    string expOut = "Travel Class = AC 3 Tier\n : Mode: Sleeping\n : Comfort: AC\n : Bunks: 3\n : Luxury: No";
    stringstream out;
    out << AC3Tier::Type();
    assert(expOut==out.str());
}

void ACChairCar::UnitTestACChairCar()
{
    const ACChairCar &i = ACChairCar::Type();
    assert(&i == &ACChairCar::Type());

    assert(true==ACChairCar::Type().IsSitting());
    assert(true==ACChairCar::Type().isAC_);
    assert(false==ACChairCar::Type().isLuxury_);

    assert(0==ACChairCar::Type().GetNumberOfTiers());
    assert("AC Chair Car"==ACChairCar::Type().GetName());
    assert(1.25==ACChairCar::Type().GetLoadFactor());

    string expOut = "Travel Class = AC Chair Car\n : Mode: Sitting\n : Comfort: AC\n : Bunks: 0\n : Luxury: No";
    stringstream out;
    out << ACChairCar::Type();
    assert(expOut==out.str());
}

void Sleeper::UnitTestSleeper()
{
    const Sleeper &i = Sleeper::Type();
    assert(&i == &Sleeper::Type());

    assert(false==Sleeper::Type().IsSitting());
    assert(false==Sleeper::Type().isAC_);
    assert(false==Sleeper::Type().isLuxury_);

    assert(3==Sleeper::Type().GetNumberOfTiers());
    assert("Sleeper"==Sleeper::Type().GetName());
    assert(1.0==Sleeper::Type().GetLoadFactor());

    string expOut = "Travel Class = Sleeper\n : Mode: Sleeping\n : Comfort: Non-AC\n : Bunks: 3\n : Luxury: No";
    stringstream out;
    out << Sleeper::Type();
    assert(expOut==out.str());
}

void SecondSitting::UnitTestSecondSitting()
{
    const SecondSitting &i = SecondSitting::Type();
    assert(&i == &SecondSitting::Type());

    assert(true==SecondSitting::Type().IsSitting());
    assert(false==SecondSitting::Type().isAC_);
    assert(false==SecondSitting::Type().isLuxury_);
    assert(0==SecondSitting::Type().GetNumberOfTiers());
    assert("Second Sitting"==SecondSitting::Type().GetName());
    assert(0.5==SecondSitting::Type().GetLoadFactor());

    string expOut = "Travel Class = Second Sitting\n : Mode: Sitting\n : Comfort: Non-AC\n : Bunks: 0\n : Luxury: No";
    stringstream out;
    out << SecondSitting::Type();
    assert(expOut==out.str());
}

int main()
{
    ACFirstClass::UnitTestACFirstClass();
    AC2Tier::UnitTestAC2Tier();
    FirstClass::UnitTestFirstClass();
    AC3Tier::UnitTestAC3Tier();
    ACChairCar::UnitTestACChairCar();
    Sleeper::UnitTestSleeper();
    SecondSitting::UnitTestSecondSitting();
    return 0;
}
