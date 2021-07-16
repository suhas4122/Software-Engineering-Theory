/*
    CS20006 Assignment 3
    UnitTestBooking.cpp
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

void Booking::UnitTestBooking()
{
    Booking b1(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), ACFirstClass::Type(), true, "BOOKING SUCCEEDED");
    assert("Kolkata"==b1.fromStation_.GetName() && "Mumbai"==b1.toStation_.GetName() && "AC First Class"==b1.bookingClass_.GetName() && 1==b1.PNR_ && NULL==b1.passenger_ && true==b1.bookingStatus_ && "BOOKING SUCCEEDED"==b1.bookingMessage_ && Date(17, 3, 2021)==(b1.date_));
    
    Booking b2(Station("Kolkata"), Station("Chennai"), Date(20, 3, 2021), ACChairCar::Type());
    assert("Kolkata"==b2.fromStation_.GetName() && "Chennai"==b2.toStation_.GetName() && "AC Chair Car"==b2.bookingClass_.GetName() && 2==b2.PNR_ && NULL==b2.passenger_ && true==b2.bookingStatus_ && "BOOKING SUCCEEDED"==b2.bookingMessage_ && Date(20, 3, 2021)==(b2.date_));

    Booking b3(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), ACFirstClass::Type(), true);
    assert("Kolkata"==b3.fromStation_.GetName() && "Mumbai"==b3.toStation_.GetName() && "AC First Class"==b3.bookingClass_.GetName() && 3==b3.PNR_ && NULL==b3.passenger_ && true==b3.bookingStatus_ && "BOOKING SUCCEEDED"==b3.bookingMessage_ && Date(17, 3, 2021)==(b3.date_));
    
    Booking b4(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), ACFirstClass::Type());
    assert("Kolkata"==b4.fromStation_.GetName() && "Mumbai"==b4.toStation_.GetName() && "AC First Class"==b4.bookingClass_.GetName() && 4==b4.PNR_ && NULL==b4.passenger_ && true==b4.bookingStatus_ && "BOOKING SUCCEEDED"==b4.bookingMessage_ && Date(17, 3, 2021)==(b4.date_));
    
    Booking b5(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), ACFirstClass::Type());
    assert(3839==b5.fare_);

    Booking b6(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), AC2Tier::Type());
    assert(2064==b6.fare_);

    Booking b7(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), FirstClass::Type());
    assert(2518==b7.fare_);

    Booking b8(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), AC3Tier::Type());
    assert(1812==b8.fare_);

    Booking b9(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), ACChairCar::Type());
    assert(1309==b9.fare_);

    Booking b10(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), Sleeper::Type());
    assert(1007==b10.fare_);

    Booking b11(Station("Kolkata"), Station("Mumbai"), Date(17, 3, 2021), SecondSitting::Type());
    assert(504==b11.fare_);

    string expOut = "BOOKING SUCCEEDED\nPNR Number = 1\nFrom Station = Kolkata\nTo Station = Mumbai\nTravel Date = Wed, 17/Mar/2021\n\nTravel Class = AC First Class\n : Mode: Sleeping\n : Comfort: AC\n : Bunks: 2\n : Luxury: Yes\nFare = 3839\n";
    
    stringstream out;
    out << b1;
    assert(expOut==out.str());
}

int main()
{
    Booking::UnitTestBooking();
    return 0;
}
