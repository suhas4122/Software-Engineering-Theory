# Inheritance Hierarchy, Design, Analysis & Testing

This is a documentation report made for Railway Booking System made by **Suhas Jain** as an assignment in **Software Engineering Theory** course. <br/>
This file contains details of various headers and source files like the contents and their role in the project. Instructions on how to compile and test the project are also provided below.<br/>
**Note:** C++ 11 version is used while making and testing this project.

## Information of Header and Source Files
- **Station.h** <br/>
Header file for Station class and contains the declaration of all the data members, constructors and member functions of the Station class.
- **Station.cpp**<br/>
The source file for the Station class that contains the implementations of all the constructors and member functions declared in Station.h.
- **UnitTestStation.cpp**<br/>
This file contains the body of unit testing function of the Station class.
- **Railways.h** <br/>
Header file for Railways class and contains the declaration of all the data members, constructors and member functions of the Railways class.
- **Railways.cpp**<br/>
The source file for the Railways class that contains the implementations of all the constructors and member functions declared in Railways.h.
- **UnitTestRailways.cpp**<br/>
This file contains the body of unit testing function of the Railways class.
- **Date.h** <br/>
Header file for Date class and contains the declaration of all the data members, constructors and member functions of the Date class.
- **Date.cpp**<br/>
The source file for the Date class that contains the implementations of all the constructors and member functions declared in Date.h.
- **UnitTestDate.cpp**<br/>
This file contains the body of unit testing function of the Date class.
- **BookingClasses.h** <br/>
Header file for BookingClasses class and contains the declaration of all the data members, constructors and member functions of the BookingClasses class.
- **BookingClasses.cpp**<br/>
The source file for the BookingClasses class that contains the implementations of all the constructors and member functions declared in BookingClasses.h.
- **UnitTestBookingClasses.cpp**<br/>
This file contains the body of unit testing function of the BookingClasses class.
- **Booking.h** <br/>
Header file for Booking class and contains the declaration of all the data members, constructors and member functions of the Booking class.
- **Booking.cpp**<br/>
The source file for the Booking class that contains the implementations of all the constructors and member functions declared in Booking.h.
- **UnitTestBooking.cpp**<br/>
This file contains the body of unit testing function of the Booking class.

## Compilation and Build Instructions for Application Testing 
To run the test application inside Application.cpp navigate to the folder where all the source and test files are stored and run the below command in the terminal : 
>$ make <br/>
>$ ./rbs

By default application file selected by the makefile is Application.cpp. You can change the the application file with which you want to test or default application file that was provided in the problem statement. For changing the application file there is no need to modify the makefile, you can just pass the name of your application file without .cpp extension as an argument to the make command like below:
>$ make APPFILE=ApplicationTestGiven<br/>
>$ ./rbs  
## Compilation and Build Instructions for Unit Testing a Individual Class
- For unit testing Station class, use the following command 
>$ g++ -std=c++11 Station.cpp Railways.cpp UnitTestStation.cpp -o test<br/>
>$ ./test
- For unit testing Railways class, use the following command 
>$ g++ -std=c++11 Railways.cpp Station.cpp UnitTestRailways.cpp -o test<br/>
>$ ./test
- For unit testing Date class, use the following command 
>$ g++ -std=c++11 Date.cpp UnitTestDate.cpp -o test<br/>
>$ ./test
- For unit testing BookingClasses class, use the following command 
>$ g++ -std=c++11 BookingClasses.cpp UnitTestBookingClasses.cpp -o test<br/>
>$ ./test
- For unit testing Booking class, use the following command 
>$ g++ -std=c++11 Booking.cpp BookingClasses.cpp Railways.cpp Date.cpp Station.cpp UnitTestBooking.cpp -o test<br/>
>$ ./test

If there is no exception nothing will be printed, in base of an exception compiler will specify which assert statement caused the error.