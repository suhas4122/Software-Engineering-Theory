/*
    CS20006 Assignment 5
    Booking.cpp
    By : Suhas Jain
    Roll No : 19CS30048
*/

// Source File for class Booking

// Including project header files
#include "Booking.h"

// Initializing the static variables
int Booking::sBookingPNRSerial = 1;
// const double Booking::sBaseFarePerKM = 0.50; // To be put in application
vector<Booking*> Booking::sBookings;


Booking* Booking::ReserveBooking(const string& fromStationName, const string& toStationName, const string& bookingDate, const BookingClass& bookingClass, const BookingCategory& bookingCategory, const Passenger* passenger, bool bookingStatus, const string& bookingMessage)
{
    //flag to store if there is any exception in the program before making the object
    bool flag = 0;

    //if passenger details are not provided the booking is invalid 
    if(passenger == NULL)
    {
        flag = 1;
    }

    
    const Date* dateOfBooking = NULL;

    //Making a local pointer pointing to the date of booking
    try {
        dateOfBooking = Date::CreateDate(bookingDate);
    } catch(Bad_Date& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    if(dateOfBooking == NULL)
    {
        throw Bad_Booking("Invalid Booking Information");
    }        
    
    //Making a local pointer pointing to the source station
    const Station* fromStation = NULL;
    try {
        fromStation = Railways::IndianRailways().GetStation(fromStationName);
    } catch(Bad_Station& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    //Making a local pointer pointing to the destination station
    const Station* toStation = NULL;
    try {
        toStation = Railways::IndianRailways().GetStation(toStationName);
    } catch(Bad_Station& e) {
        cout << e.what() << endl;
        flag = 1;
    }

    //Checking if the source and destination stations are the same
    try {
        if(fromStation == toStation && fromStation != NULL && toStation != NULL){
            throw Same_Stations("Source and destination stations cannot be same");
        }            
    } catch (Same_Stations& e) {
        cout << e.what() << endl; 
        flag = 1;
    }

    //Automatically setting the date of reservation to the day booking is made
    const Date* dateOfReservation = Date::Today();

    //Checking if the date of reservation and booking follow the guidelines given in the problem statement
    try {
        if(*dateOfBooking == *dateOfReservation)
        {
            throw Invalid_Booking_Date("Booking on the same day is not allowed");
        }         
        if(!(*dateOfBooking > *dateOfReservation))
        {
            throw Invalid_Booking_Date("Date of Reservation should be earlier than Date of Booking");
        }            
        if(!((*dateOfBooking) - *dateOfReservation < Duration(1, 0, 1)))
        {
            throw Invalid_Booking_Date("Date Of Booking cannot be beyond 1 year from Date of Reservation");
        }   
    } catch(Invalid_Booking_Date& e) {
        cout << e.what() << endl;
        flag = 1;
    }


    //Checking the validity of booking categories 
    if(passenger != NULL && dateOfBooking != NULL) 
    {
        try {
            if(!bookingCategory.IsEligible(*passenger))
            {
                throw Bad_Booking("Passenger is not eligible for the booking category : " + bookingCategory.GetName());
            }                
            if((&bookingCategory == &BookingCategory::Tatkal::Type()) || (&bookingCategory == &BookingCategory::PremiumTatkal::Type())) 
            {
                if(!((*dateOfBooking) - *dateOfReservation < Duration(0, 0, 2)))
                {
                    throw Bad_Booking("Booking should be done 1 day before travel for Tatkal and Premium Tatkal bookings");
                }                    
            }
        } catch(Bad_Booking& e) {
            cout << e.what() << endl;
            flag = 1;
        }
    }

    //Throwing exception in case of any inconsistencies in booking data 
    if(flag == 1)
    {
        throw Bad_Booking("Invalid Booking Information");
    }
    
    Booking* booking = bookingCategory.CreateBooking(*fromStation, *toStation, *dateOfBooking, bookingClass, bookingCategory, *passenger, *dateOfReservation, bookingStatus, bookingMessage);
    booking -> fare_ = booking -> computeFare();

    return booking;
}

//Following fucions compute the fare for all the different categories as per the logic given in the problem statement

template<>
int Booking::GeneralBooking::computeFare() const 
{
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.50);
}

template<>
int Booking::LadiesBooking::computeFare() const 
{
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - LadiesConcession::Type().GetFactor());
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int Booking::SeniorCitizenBooking::computeFare() const 
{
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - SeniorCitizenConcession::Type().GetFactor(passenger_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int Booking::TaktalBooking::computeFare() const 
{
    int dist = Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double baseFare = Booking::sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    double tatkalFare = loadedFare * bookingClass_.GetTatkalLoadFactor();
    if(dist < bookingClass_.GetMinTatkalDistance() || tatkalFare < bookingClass_.GetMinTatkalCharge())
        tatkalFare = 0.0;
    else if(tatkalFare > bookingClass_.GetMaxTatkalCharge())
        tatkalFare = bookingClass_.GetMaxTatkalCharge();
    double finalFare = loadedFare + tatkalFare + bookingClass_.GetReservationCharge();
    // cout << baseFare << endl << loadedFare << endl << finalFare << endl;
    return static_cast<int>(finalFare + 0.5);
}

template<>
int Booking::PremiumTatkalBooking::computeFare() const 
{
    int dist = Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double baseFare = Booking::sBaseFarePerKM * dist;
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    double tatkalFare = loadedFare * bookingClass_.GetTatkalLoadFactor() * 2.00;
    if(dist < bookingClass_.GetMinTatkalDistance() || tatkalFare < bookingClass_.GetMinTatkalCharge())
        tatkalFare = 0.0;
    else if(tatkalFare > bookingClass_.GetMaxTatkalCharge())
        tatkalFare = bookingClass_.GetMaxTatkalCharge();
    double finalFare = loadedFare + (2.0 * tatkalFare) + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int DivyaangBooking::BlindBooking::computeFare() const 
{
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - DivyaangConcession::Type().GetFactor(passenger_, bookingClass_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int DivyaangBooking::OrthoHandicappedBooking::computeFare() const 
{
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - DivyaangConcession::Type().GetFactor(passenger_, bookingClass_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int DivyaangBooking::CancerBooking::computeFare() const 
{
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - DivyaangConcession::Type().GetFactor(passenger_, bookingClass_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}

template<>
int DivyaangBooking::TBBooking::computeFare() const 
{
    double baseFare = Booking::sBaseFarePerKM * Railways::IndianRailways().GetDistance(fromStation_, toStation_);
    double loadedFare = baseFare * bookingClass_.GetLoadFactor();
    loadedFare *= (1.00 - DivyaangConcession::Type().GetFactor(passenger_, bookingClass_));
    double finalFare = loadedFare + bookingClass_.GetReservationCharge();
    return static_cast<int>(finalFare + 0.5);
}


//Printing all the relevant details of the booking 
ostream& operator<<(ostream& os, const Booking& booking) 
{
    os << booking.bookingMessage_ << endl;
    os << "PNR Number = " << booking.PNR_ << endl;
    os << "From Station = " << booking.fromStation_.GetName() << endl;
    os << "To Station = " << booking.toStation_.GetName() << endl;
    os << "Travel Date = " << booking.dateOfBooking_ << endl;
    os << booking.bookingClass_ ;
    os << "Booking Category = " << booking.bookingCategory_ << endl;
    os << "Passenger Information = \n" << booking.passenger_ << endl;
    os << "Reservation Date = " << booking.dateOfReservation_ << endl;
    os << "Fare = " << booking.fare_ << endl;
    return os;
}
