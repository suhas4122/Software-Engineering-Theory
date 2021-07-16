/*
    CS20006 Assignment 5
    Application.cpp
    By : Suhas Jain
    Roll No : 19CS30048
*/

// Application Test File for the entire project

// Including project header files
#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "Gender.h"
#include "Name.h"
#include "Passenger.h"
#include "BookingClass.h"
#include "BookingCategory.h"
#include "Concession.h"
#include "Booking.h"

// Initializing static constants
template<> const double BookingClass::ACFirstClass::sLoadFactor = 6.50;
template<> const bool BookingClass::ACFirstClass::sIsLuxury = true;
template<> const double BookingClass::ACFirstClass::sReservationCharge = 60.00;
template<> const double BookingClass::ACFirstClass::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::ACFirstClass::sMinTatkalCharge = 400.00;
template<> const double BookingClass::ACFirstClass::sMaxTatkalCharge = 500.00;
template<> const int BookingClass::ACFirstClass::sMinTatkalDistance = 500;

template<> const double BookingClass::ExecutiveChairCar::sLoadFactor = 5.00;
template<> const bool BookingClass::ExecutiveChairCar::sIsLuxury = true;
template<> const double BookingClass::ExecutiveChairCar::sReservationCharge = 60.00;
template<> const double BookingClass::ExecutiveChairCar::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::ExecutiveChairCar::sMinTatkalCharge = 400.00;
template<> const double BookingClass::ExecutiveChairCar::sMaxTatkalCharge = 500.00;
template<> const int BookingClass::ExecutiveChairCar::sMinTatkalDistance = 250;

template<> const double BookingClass::AC2Tier::sLoadFactor = 4.00;
template<> const bool BookingClass::AC2Tier::sIsLuxury = false;
template<> const double BookingClass::AC2Tier::sReservationCharge = 50.00;
template<> const double BookingClass::AC2Tier::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::AC2Tier::sMinTatkalCharge = 400.00;
template<> const double BookingClass::AC2Tier::sMaxTatkalCharge = 500.00;
template<> const int BookingClass::AC2Tier::sMinTatkalDistance = 500;

template<> const double BookingClass::FirstClass::sLoadFactor = 3.00;
template<> const bool BookingClass::FirstClass::sIsLuxury = true;
template<> const double BookingClass::FirstClass::sReservationCharge = 50.00;
template<> const double BookingClass::FirstClass::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::FirstClass::sMinTatkalCharge = 400.00;
template<> const double BookingClass::FirstClass::sMaxTatkalCharge = 500.00;
template<> const int BookingClass::FirstClass::sMinTatkalDistance = 500;

template<> const double BookingClass::AC3Tier::sLoadFactor = 2.50;
template<> const bool BookingClass::AC3Tier::sIsLuxury = false;
template<> const double BookingClass::AC3Tier::sReservationCharge = 40.00;
template<> const double BookingClass::AC3Tier::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::AC3Tier::sMinTatkalCharge = 300.00;
template<> const double BookingClass::AC3Tier::sMaxTatkalCharge = 400.00;
template<> const int BookingClass::AC3Tier::sMinTatkalDistance = 500;

template<> const double BookingClass::ACChairCar::sLoadFactor = 2.00;
template<> const bool BookingClass::ACChairCar::sIsLuxury = false;
template<> const double BookingClass::ACChairCar::sReservationCharge = 40.00;
template<> const double BookingClass::ACChairCar::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::ACChairCar::sMinTatkalCharge = 125.00;
template<> const double BookingClass::ACChairCar::sMaxTatkalCharge = 225.00;
template<> const int BookingClass::ACChairCar::sMinTatkalDistance = 250;

template<> const double BookingClass::Sleeper::sLoadFactor = 1.00;
template<> const bool BookingClass::Sleeper::sIsLuxury = false;
template<> const double BookingClass::Sleeper::sReservationCharge = 20.00;
template<> const double BookingClass::Sleeper::sTatkalLoadFactor = 0.30;
template<> const double BookingClass::Sleeper::sMinTatkalCharge = 100.00;
template<> const double BookingClass::Sleeper::sMaxTatkalCharge = 200.00;
template<> const int BookingClass::Sleeper::sMinTatkalDistance = 500;

template<> const double BookingClass::SecondSitting::sLoadFactor = 0.60;
template<> const bool BookingClass::SecondSitting::sIsLuxury = false;
template<> const double BookingClass::SecondSitting::sReservationCharge = 15.00;
template<> const double BookingClass::SecondSitting::sTatkalLoadFactor = 0.10;
template<> const double BookingClass::SecondSitting::sMinTatkalCharge = 10.00;
template<> const double BookingClass::SecondSitting::sMaxTatkalCharge = 15.00;
template<> const int BookingClass::SecondSitting::sMinTatkalDistance = 100;

const double Booking::sBaseFarePerKM = 0.50; 

// Test application for booking
void BookingApplication() 
{   
    //General Booking
    const Passenger* p = NULL;
    try {
        p = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/2002", Gender::Male::Type(), "100011111111");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    Booking* b = NULL;
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::General::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Ladies Booking 
    try {
        p = Passenger::CreatePassenger("Daaki", "Mangali", "Singh", "11/07/1992", Gender::Female::Type(), "100011111111");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::Ladies::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Senior Citizen Male booking
    try {
        p = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/1950", Gender::Male::Type(), "100011111111");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC2Tier::Type(), BookingCategory::SeniorCitizen::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Senior Citizen Female booking
    try {
        p = Passenger::CreatePassenger("Daaki", "Mangali", "Singh", "11/03/1961", Gender::Female::Type(), "100011111111");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Mumbai", "Bangalore", "15/02/2022", BookingClass::FirstClass::Type(), BookingCategory::SeniorCitizen::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Tatkal and premium tatkal for normal person
    try {
        p = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/2002", Gender::Male::Type(), "100011111111");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "10/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::Tatkal::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "10/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::PremiumTatkal::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Tatkal and Premium Tatakal for person who can avail concession (cannot avail in this case) 
    try {
        p = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/2002", Gender::Male::Type(), "100011111111", &Divyaang::Blind::Type(), "0221");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "10/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::Tatkal::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "10/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::PremiumTatkal::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Booking for Divyaang - Blind
    try {
        p = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/2002", Gender::Male::Type(), "100011111111", &Divyaang::Blind::Type(), "0221");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::Blind::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Booking for Divyaang - Orthopedically Handicapped
    try {
        p = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/2002", Gender::Male::Type(), "100011111111", &Divyaang::OrthoHandicapped::Type(), "0221");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::OrthoHandicapped::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Booking for Divyaang - Cancer Patient
    try {
        p = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/2002", Gender::Male::Type(), "100011111111", &Divyaang::Cancer::Type(), "0221");
    } catch(Bad_Passenger& e) {
        //Already halted
    }
    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::Cancer::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }


    //Booking for Divyaang - TB Patient
    try {
        p = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/2002", Gender::Male::Type(), "100011111111", &Divyaang::TB::Type(), "0221");
    } catch(Bad_Passenger& e) {
        //Already halted
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::TB::Type(), p);
    } catch(Bad_Booking& e) {
        //Already halted
    }

    
    int i = 1;
    for(auto x : Booking::sBookings)
    {
        cout << "*** Positive Booking no." << i << " ***" << endl << endl; 
        cout << (*x) <<endl;
        i++;
    }
    
}
    
int main() 
{
    BookingApplication();

    return 0;
}