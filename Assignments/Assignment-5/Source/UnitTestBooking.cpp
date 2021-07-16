/*
    CS20006 Assignment 5
    UnitTestBooking.cpp
    By : Suhas Jain
    Roll No : 19CS30048
*/

/*
    COMPILATION AND BUILD COMMANDS :
    g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestBooking.cpp -o test
    ./test
*/

// Unit Testing File for class Booking

// Including project header files
#include "Booking.h"

// C++ Headers
#include <cassert>
#include <sstream>

// Initializing the required static constants
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

const double Booking::sBaseFarePerKM = 0.5;

void Booking::UnitTestBooking()
{
    /*
        POSITIVE TEST CASES 
    */
    const Passenger* pgeneral = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/1975", Gender::Male::Type(), "123456789012");
    const Passenger* pladies = Passenger::CreatePassenger("Daaki", "Mangali", "Singh", "11/03/1978", Gender::Female::Type(), "123456789012");
    const Passenger* pseniorm = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012");
    const Passenger* pseniorf = Passenger::CreatePassenger("Daaki", "Mangali", "Singh", "11/03/1961", Gender::Female::Type(), "123456789012");
    const Passenger* pblind = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012", &Divyaang::Blind::Type(), "012");
    const Passenger* portho = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/1950", Gender::Male::Type(), "123456789012", &Divyaang::OrthoHandicapped::Type(), "012");
    const Passenger* pcancer = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/1950", Gender::Female::Type(), "123456789012", &Divyaang::Cancer::Type(), "012");
    const Passenger* ptb = Passenger::CreatePassenger("Daaku", "Mangal", "Singh", "11/03/1950", Gender::Female::Type(), "123456789012", &Divyaang::TB::Type(), "012");


    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 1\nFrom Station = Delhi\nTo Station = Mumbai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 1849\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Kolkata", "Delhi", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::Ladies::Type(), pladies);
        string s = "BOOKING SUCCEEDED\nPNR Number = 2\nFrom Station = Kolkata\nTo Station = Delhi\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Ladies\nPassenger Information = \nName: Daaki Mangali Singh\nDate Of Birth: Sat, 11/Mar/1978\nGender: Female\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 1880\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Chennai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::SeniorCitizen::Type(), pseniorm);
        string s = "BOOKING SUCCEEDED\nPNR Number = 3\nFrom Station = Delhi\nTo Station = Chennai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Senior Citizen\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Sat, 11/Mar/1950\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 1675\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Bangalore", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::SeniorCitizen::Type(), pseniorf);
        string s = "BOOKING SUCCEEDED\nPNR Number = 4\nFrom Station = Delhi\nTo Station = Bangalore\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Senior Citizen\nPassenger Information = \nName: Daaki Mangali Singh\nDate Of Birth: Sat, 11/Mar/1961\nGender: Female\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 1384\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Bangalore", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::Tatkal::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 5\nFrom Station = Bangalore\nTo Station = Mumbai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Tatkal\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 1634\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Chennai", "Bangalore", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::PremiumTatkal::Type(), pladies);
        string s = "BOOKING SUCCEEDED\nPNR Number = 6\nFrom Station = Chennai\nTo Station = Bangalore\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Premium Tatkal\nPassenger Information = \nName: Daaki Mangali Singh\nDate Of Birth: Sat, 11/Mar/1978\nGender: Female\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 478\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Bangalore", "Chennai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::Blind::Type() , pblind);
        string s = "BOOKING SUCCEEDED\nPNR Number = 7\nFrom Station = Bangalore\nTo Station = Chennai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Divyaang - Blind\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Sat, 11/Mar/1950\nGender: Male\nAadhaar: 123456789012\nDisability Type: Blind\nDisability ID: 012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 149\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Kolkata", "Mumbai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::Cancer::Type(), pcancer);
        string s = "BOOKING SUCCEEDED\nPNR Number = 8\nFrom Station = Kolkata\nTo Station = Mumbai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Divyaang - Cancer\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Sat, 11/Mar/1950\nGender: Female\nAadhaar: 123456789012\nDisability Type: Cancer\nDisability ID: 012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 40\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Mumbai", "Chennai", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::OrthoHandicapped::Type(), portho);
        string s = "BOOKING SUCCEEDED\nPNR Number = 9\nFrom Station = Mumbai\nTo Station = Chennai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Divyaang - Orthopaedically Handicapped\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Sat, 11/Mar/1950\nGender: Male\nAadhaar: 123456789012\nDisability Type: Orthopaedically Handicapped\nDisability ID: 012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 458\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Chennai", "Kolkata", "15/04/2021", BookingClass::AC3Tier::Type(), Divyaang::TB::Type(), ptb);
        string s = "BOOKING SUCCEEDED\nPNR Number = 10\nFrom Station = Chennai\nTo Station = Kolkata\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = Divyaang - TB\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Sat, 11/Mar/1950\nGender: Female\nAadhaar: 123456789012\nDisability Type: TB\nDisability ID: 012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 2114\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Mumbai", "15/04/2021", BookingClass::ACFirstClass::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 11\nFrom Station = Delhi\nTo Station = Mumbai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC First Class\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 2\n  : Luxury: Yes\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 4763\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Kolkata", "Mumbai", "15/04/2021", BookingClass::AC2Tier::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 12\nFrom Station = Kolkata\nTo Station = Mumbai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 2 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 2\n  : Luxury: No\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 4078\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Kolkata", "Chennai", "15/04/2021", BookingClass::AC3Tier::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 13\nFrom Station = Kolkata\nTo Station = Chennai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC 3 Tier\n  : Mode: Sleeping\n  : Comfort: AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 2114\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Delhi", "Bangalore", "15/04/2021", BookingClass::ACChairCar::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 14\nFrom Station = Delhi\nTo Station = Bangalore\nTravel Date = Thu, 15/Apr/2021\nTravel Class = AC Chair Car\n  : Mode: Sitting\n  : Comfort: AC\n  : Bunks: 0\n  : Luxury: No\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 2190\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Bangalore", "Mumbai", "15/04/2021", BookingClass::FirstClass::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 15\nFrom Station = Bangalore\nTo Station = Mumbai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = First Class\n  : Mode: Sleeping\n  : Comfort: Non-AC\n  : Bunks: 2\n  : Luxury: Yes\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 1522\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Bangalore", "Kolkata", "15/04/2021", BookingClass::Sleeper::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 16\nFrom Station = Bangalore\nTo Station = Kolkata\nTravel Date = Thu, 15/Apr/2021\nTravel Class = Sleeper\n  : Mode: Sleeping\n  : Comfort: Non-AC\n  : Bunks: 3\n  : Luxury: No\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 956\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Chennai", "Kolkata", "15/04/2021", BookingClass::SecondSitting::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 17\nFrom Station = Chennai\nTo Station = Kolkata\nTravel Date = Thu, 15/Apr/2021\nTravel Class = Second Sitting\n  : Mode: Sitting\n  : Comfort: Non-AC\n  : Bunks: 0\n  : Luxury: No\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 513\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }

    try {
        Booking* b = Booking::ReserveBooking("Kolkata", "Mumbai", "15/04/2021", BookingClass::ExecutiveChairCar::Type(), BookingCategory::General::Type(), pgeneral);
        string s = "BOOKING SUCCEEDED\nPNR Number = 18\nFrom Station = Kolkata\nTo Station = Mumbai\nTravel Date = Thu, 15/Apr/2021\nTravel Class = Executive Chair Car\n  : Mode: Sitting\n  : Comfort: AC\n  : Bunks: 0\n  : Luxury: Yes\nBooking Category = General\nPassenger Information = \nName: Daaku Mangal Singh\nDate Of Birth: Tue, 11/Mar/1975\nGender: Male\nAadhaar: 123456789012\n\nReservation Date = Fri, 9/Apr/2021\nFare = 5095\n"; 
        stringstream out;
        out << (*b);
        assert(s == out.str());
    } catch(Bad_Booking& e) {
        cout << e.what() << endl;
    }
    

    /*
        NEGATIVE TEST CASES 
    */
}

int main()
{
    Booking::UnitTestBooking();

    return 0;
}