/*
    CS20006 Assignment 3
    ApplicationTest
    Suhas Jain (19CS30048)
*/

#include "Station.h"
#include "Railways.h"
#include "Date.h"
#include "BookingClasses.h"
#include "Booking.h"
#include "Passenger.h"

const double ACFirstClass::sLoadFactor = 3.00;
const double AC2Tier::sLoadFactor = 2.00;
const double FirstClass::sLoadFactor = 2.00;
const double AC3Tier::sLoadFactor = 1.75;
const double ACChairCar::sLoadFactor = 1.25;
const double Sleeper::sLoadFactor = 1.00;
const double SecondSitting::sLoadFactor = 0.50;

const double Booking::sBaseFarePerKM = 0.5;
const int Booking::sACSurcharge = 50;
const int Booking::sLuxuryTaxPercent = 25;

// Test application for booking
void ApplicationTest() 
{
    //Testing Everything in booking a ticket from Kolkata to Mumbai 
    cout<<"\n***TEST CASE 1***\n\n";
    const Railways& IndianRailways1 = Railways::Type();
    // cout<<IndianRailways<<endl;
    Station s1("Kolkata"); 
    Station s2("Mumbai");
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<"Distance = "<<s1.GetDistance(s2)<<endl;
    cout<<"Golden Distance = "<<IndianRailways1.GetDistance(s1, s2)<<endl;
    const BookingClasses &bc1 = FirstClass::Type();
    cout<<bc1<<endl;
    Date dt1(10, 3, 2021);
    cout<<dt1<<endl;
    Booking bkng1(s1, s2, dt1, bc1);
    Booking bkng2(s2, s1, dt1, bc1);

    //Testing Everything in booking a ticket from Chennai and Delhi 
    cout<<"\n***TEST CASE 2***\n\n";
    const Railways& IndianRailways2 = Railways::Type();
    // cout<<IndianRailways<<endl;
    Station s3("Chennai"); 
    Station s4("Delhi");
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<"Distance = "<<s3.GetDistance(s4)<<endl;
    cout<<"Golden Distance = "<<IndianRailways2.GetDistance(s3, s4)<<endl;
    const BookingClasses &bc2 = ACFirstClass::Type();
    cout<<bc2<<endl;
    Date dt2(11, 4, 2021);
    cout<<dt2<<endl;
    Booking bkng3(s3, s4, dt1, bc1);
    Booking bkng4(s4, s3, dt1, bc1);

    //Testing Everything in booking a ticket from Bangalore to Kolkata
    cout<<"\n***TEST CASE 3***\n\n";
    const Railways& IndianRailways3 = Railways::Type();
    // cout<<IndianRailways<<endl;
    Station s5("Bangalore"); 
    Station s6("Kolkata");
    cout<<s5<<endl;
    cout<<s6<<endl;
    cout<<"Distance = "<<s5.GetDistance(s6)<<endl;
    cout<<"Golden Distance = "<<IndianRailways3.GetDistance(s5, s6)<<endl;
    const BookingClasses &bc3 = ACChairCar::Type();
    cout<<bc3<<endl;
    Date dt3(15, 3, 2021);
    cout<<dt3<<endl;
    Booking bkng5(s5, s6, dt3, bc3);
    Booking bkng6(s6, s5, dt3, bc3);

    //Testing Everything in booking a ticket from Kolkata to Chennai
    cout<<"\n***TEST CASE 4***\n\n";
    const Railways& IndianRailways4 = Railways::Type();
    // cout<<IndianRailways<<endl;
    Station s7("Kolkata"); 
    Station s8("Chennai");
    cout<<s7<<endl;
    cout<<s8<<endl;
    cout<<"Distance = "<<s7.GetDistance(s8)<<endl;
    cout<<"Golden Distance = "<<IndianRailways4.GetDistance(s7, s8)<<endl;
    const BookingClasses &bc4 = AC2Tier::Type();
    cout<<bc4<<endl;
    Date dt4(15, 9, 2022);
    cout<<dt4<<endl;
    Booking bkng7(s7, s8, dt4, bc4);
    Booking bkng8(s8, s7, dt4, bc4);

    //Testing Everything in booking a ticket from Delhi to Bangalore
    cout<<"\n***TEST CASE 5***\n\n";
    const Railways& IndianRailways5 = Railways::Type();
    // cout<<IndianRailways<<endl;
    Station s9("Delhi"); 
    Station s10("Bangalore");
    cout<<s9<<endl;
    cout<<s10<<endl;
    cout<<"Distance = "<<s9.GetDistance(s10)<<endl;
    cout<<"Golden Distance = "<<IndianRailways5.GetDistance(s9, s10)<<endl;
    const BookingClasses &bc5 = AC3Tier::Type();
    cout<<bc5<<endl;
    Date dt5(16, 9, 2021);
    cout<<dt5<<endl;
    Booking bkng9(s9, s10, dt5, bc5);
    Booking bkng10(s10, s9, dt5, bc5);

    //Testing Everything in booking a ticket from Mumbai to Delhi 
    cout<<"\n***TEST CASE 6***\n\n";
    const Railways& IndianRailways6 = Railways::Type();
    // cout<<IndianRailways<<endl;
    Station s11("Mumbai"); 
    Station s12("Delhi");
    cout<<s11<<endl;
    cout<<s12<<endl;
    cout<<"Distance = "<<s11.GetDistance(s12)<<endl;
    cout<<"Golden Distance = "<<IndianRailways6.GetDistance(s11, s12)<<endl;
    const BookingClasses &bc6 = Sleeper::Type();
    cout<<bc6<<endl;
    Date dt6(04, 12, 2021);
    cout<<dt6<<endl;
    Booking bkng11(s11, s12, dt6, bc6);
    Booking bkng12(s12, s11, dt6, bc6);

    //Testing Everything in booking a ticket from Chennai to Bangalore
    cout<<"\n***TEST CASE 7***\n\n";
    const Railways& IndianRailways7 = Railways::Type();
    // cout<<IndianRailways<<endl;
    Station s13("Chennai"); 
    Station s14("Bangalore");
    cout<<s13<<endl;
    cout<<s14<<endl;
    cout<<"Distance = "<<s13.GetDistance(s14)<<endl;
    cout<<"Golden Distance = "<<IndianRailways7.GetDistance(s13, s14)<<endl;
    const BookingClasses &bc7 = SecondSitting::Type();
    cout<<bc7<<endl;
    Date dt7(10, 11, 2021);
    cout<<dt7<<endl;
    Booking bkng13(s13, s14, dt7, bc7);
    Booking bkng14(s14, s13, dt7, bc7);

    cout<<"\n***PRINTING ALL BOOKINGS***\n\n";
    //Output the bookings done where sBookings is the collection of bookings done
    int i1 = 1;
    vector<Booking*>::iterator it;
    for (it = Booking::sBookings.begin(); it < Booking::sBookings.end(); ++it) 
    {
        cout << "Booking Number "<<i1<<endl;
        cout << *(*it) << endl;
        i1++;
    }

    return;
}
    
int main() 
{
    ApplicationTest();
    return 0;
}