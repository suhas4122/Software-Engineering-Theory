/*
    CS20006 Assignment 5
    BookingCategory.cpp
    By : Suhas Jain
    Roll No : 19CS30048
*/

// Source File for class BookingCategory

#include "BookingCategory.h"
#include "Booking.h"

//Initialising the names of the static constants for different booking categories
template<> const string BookingCategory::General::sName = "General";
template<> const string BookingCategory::Ladies::sName = "Ladies";
template<> const string BookingCategory::SeniorCitizen::sName = "Senior Citizen";
template<> const string BookingCategory::Tatkal::sName = "Tatkal";
template<> const string BookingCategory::PremiumTatkal::sName = "Premium Tatkal";

//Initialising the names of the static constants for different types of Divyaang
template<> const string Divyaang::Blind::sName = "Divyaang - Blind";
template<> const string Divyaang::OrthoHandicapped::sName = "Divyaang - Orthopaedically Handicapped";
template<> const string Divyaang::Cancer::sName = "Divyaang - Cancer";
template<> const string Divyaang::TB::sName = "Divyaang - TB";

//Function definitions to check eligibility of all the booking categories according to
//the guidelines and rules mentioned in the problem statement
template<>
const bool BookingCategory::General::IsEligible(const Passenger& p) const 
{
    return true;
}

template<>
const bool BookingCategory::Ladies::IsEligible(const Passenger& p) const 
{
    if(Gender::IsMale(p.GetGender()) == false)
        return true;
    else if(Gender::IsMale(p.GetGender()) && (*Date::Today() - p.GetDateOfBirth()).GetYears() < 12)
        return true;
    return false;
}

template<>
const bool BookingCategory::SeniorCitizen::IsEligible(const Passenger& p) const 
{
    if(Gender::IsMale(p.GetGender()) && (*Date::Today() - p.GetDateOfBirth()).GetYears() >= 60)
        return true;
    else if (!Gender::IsMale(p.GetGender()) && (*Date::Today() - p.GetDateOfBirth()).GetYears() >= 58)
        return true;
    return false;
}

template<>
const bool BookingCategory::Tatkal::IsEligible(const Passenger& p) const 
{
    return true;
}

template<>
const bool BookingCategory::PremiumTatkal::IsEligible(const Passenger& p) const 
{
    return true;
}

template<>
const bool Divyaang::Blind::IsEligible(const Passenger& p) const 
{
    if(p.GetDisability() == &Divyaang::Blind::Type())
        return true;
    return false;
}

template<>
const bool Divyaang::OrthoHandicapped::IsEligible(const Passenger& p) const 
{
    if(p.GetDisability() == &Divyaang::OrthoHandicapped::Type())
        return true;
    return false;
}

template<>
const bool Divyaang::Cancer::IsEligible(const Passenger& p) const
{
    if(p.GetDisability() == &Divyaang::Cancer::Type())
        return true;
    return false;
}

template<>
const bool Divyaang::TB::IsEligible(const Passenger& p) const 
{
    if(p.GetDisability() == &Divyaang::TB::Type())
        return true;
    return false;
}

//functions to call constructors and create bookings for all the different Booking Categories

template<>
Booking* BookingCategory::General::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new Booking::GeneralBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

template<>
Booking* BookingCategory::Ladies::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new Booking::LadiesBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

template<>
Booking* BookingCategory::SeniorCitizen::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new Booking::SeniorCitizenBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

template<>
Booking* BookingCategory::Tatkal::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new Booking::TaktalBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

template<>
Booking* BookingCategory::PremiumTatkal::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new Booking::PremiumTatkalBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

template<>
Booking* Divyaang::Blind::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new DivyaangBooking::BlindBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

template<>
Booking* Divyaang::OrthoHandicapped::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new DivyaangBooking::OrthoHandicappedBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

template<>
Booking* Divyaang::Cancer::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new DivyaangBooking::CancerBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

template<>
Booking* Divyaang::TB::CreateBooking(const Station& fromStation, const Station& toStation, const Date& dateOfBooking, const BookingClass& bookingClass, 
                            const BookingCategory& bookingCategory, const Passenger& passenger, const Date& dateOfReservation,  
                            bool bookingStatus, const string& bookingMessage) const
{
    return new DivyaangBooking::TBBooking(fromStation, toStation, dateOfBooking, bookingClass, bookingCategory, passenger, dateOfReservation);
}

//Overloaded output streaming operator to print the name of the Booking Category
ostream& operator<<(ostream& os, const BookingCategory& bookingCategory) 
{
    os << bookingCategory.GetName();
    return os;
}