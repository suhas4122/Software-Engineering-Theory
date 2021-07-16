/*
    CS20006 Assignment 3
    Booking.cpp
    Suhas Jain (19CS30048)
*/

// Including project header files
#include "Booking.h"

// Initializing the static variables
int Booking::sBookingPNRSerial = 1;
vector<Booking*> Booking::sBookings;

Booking::Booking(const Station& fromStation, const Station& toStation, const Date& date, const BookingClasses& bookingClass, bool bookingStatus, const string& bookingMessage, Passenger* passenger):
fromStation_(fromStation), toStation_(toStation), date_(date), bookingClass_(bookingClass), bookingStatus_(bookingStatus), bookingMessage_(bookingMessage), passenger_(passenger), PNR_(Booking::sBookingPNRSerial)
{
    fare_ = this -> ComputeFare();
    Booking::sBookings.push_back(this);
    Booking::sBookingPNRSerial++;

    #if _DEBUG
        cout << "Booking Created\n";
    #endif // _DEBUG
}

Booking::~Booking()
{
    #if _DEBUG
        cout << "Booking Destroyed\n";
    #endif // _DEBUG
}

int Booking::ComputeFare()
{
    // Implementation of the fare computation logic
    double fare;
    fare = Booking::sBaseFarePerKM * Railways::Type().GetDistance(fromStation_, toStation_);
    fare = fare * bookingClass_.GetLoadFactor();
    if(bookingClass_.IsAC())
    {
        fare += Booking::sACSurcharge;
    }
    if(bookingClass_.IsLuxury())
    {
        fare += fare * (Booking::sLuxuryTaxPercent / 100.0);
    }
    int rounded_fare = static_cast<int>(round(fare));
    return rounded_fare;
}

ostream& operator<<(ostream& os, const Booking& booking)
{
    os << booking.bookingMessage_ << endl;
    os << "PNR Number = " << booking.PNR_ << endl;
    os << "From Station = " << booking.fromStation_.GetName() << endl;
    os << "To Station = " << booking.toStation_.GetName() << endl;
    os << "Travel Date = " << booking.date_ << endl;
    os << booking.bookingClass_ <<endl;
    os << "Fare = " << booking.fare_ << endl;
    return os;
}

