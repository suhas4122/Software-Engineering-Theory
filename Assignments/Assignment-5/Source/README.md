<!-- 
    CS20006 Assignment 3
    README.md
    By : Suhas Jain
    Roll No : 19CS30048 
-->

# Railway Booking System

A rudimentary railway booking / reservation system designed by **Suhas Jain (18CS30048)** as an assignment in the Software Engineering Theory (CS20006) course.
This README file contains the details of the various header and source files used. It also has the instructions to compile and build the entire project and the instructions to compile and run the unit tests for each class. 

## Details of Various Header and Source Files

- **Station.h**  
This is the header file for the `Station` class and contains the declarations of all the data members, constructors and member functions of the `Station` class.

- **Station.cpp**  
This is the source file for the `Station` class. It contains the implementations of all the constructors and member functions declared in `Station.h`.

- **UnitTestStation.cpp**  
This file contains the function body for the unit testing function and all the test cases of the `Station` class.

- **Railways.h**  
This is the header file for the singleton `Railways` class and contains the declarations of all the data members and member functions of the `Railways` class.  

- **Railways.cpp**  
This is the source file for the `Railways` class. It contains the initializations of the static constants and the function bodies of the member functions in the `Railways` class.

- **UnitTestRailways.cpp**  
This file contains the function body for the unit testing function and all the test cases of the `Railways` class.

- **Date.h**  
This is the header file for the `Date` class and contains the declarations of all the data members, constructors and member functions of this class.

- **Date.cpp**  
This is the source file for the `Date` class. In this file, we first initialize the static constants of the `Date` class. Then we implement all the constructors and member functions declared in `Date.h`.

- **UnitTestDate.cpp**  
This file contains the function body for the unit testing function with all the test cases of the `Date` class.

- **BookingClass.h**  
This is the header file for the hierarchy of the various booking classes. The root is the abstract base class `BookingClass`. We have the 8 concrete derived classes modelled by parametric and inclusing polymorphism - `ACFirstClass`,  `Executive Chair Car`,  `AC2Tier`, `FirstClass`, `AC3Tier`, `ACChairCar` `Sleeper` and `SecondSitting`. All 8 of these are singleton classes.

- **BookingClass.cpp**  
This is the source file for the hierarchy of booking classes. It contains the implementations of all the constructors and member functions declared in `BookingClass.h`.

- **UnitTestBookingClass.cpp**  
This file contains the function bodies for the unit testing functions of the 8 concrete booking classes. Here we also check the static constants are initialised properly in   `BookingClass.cpp`

- **Passenger.h**  
This is the header file for the `Passenger` class and contains the declarations of the data members of the `Passenger` class. 

- **Passenger.cpp**
This is the header file for the `Passenger` class and contains the declarations of all the data members, constructors and member functions of this class.

- **UnitTestPassenger.cpp**  
This file contains the function body for the unit testing function  with all the test cases of the `Passenger` class.

- **BookingCategories.h**  
This is the header file for the `BookingCategories` class. It contains the declarations of all the data members, constructors and member functions of this class. `BookingCategories` is a abstract base class. Using inclusion and parametric polymorphism it has 5 concrete derived classes - `General`, `Ladies`, `SeniorCitizen`, `Tatkal`, `PremiumTatkal`. It also has another derived class `Divyaang` which in itself is a polymorphic hierarchy with 4 base classes - `Blind`, `OrthoHandicapped`, `Cancer`, `TB`.

- **BookingCategories.cpp**  
This is the source file for the `BookingCategories` class. Here, we first initialize few of the static variables. Then we implement all the constructors and member functions declared in `BookingCategories.h`.

- **UnitTestBookingCategories.cpp**  
This file contains the function body for the unit testing function of the `BookingCategories` class.

- **Booking.h**  
This is the header file for the `Booking` class. It contains the declarations of all the data members, constructors and member functions of this class. `Booking` is a abstract base class. Using inclusion and parametric polymorphism it has 5 concrete derived classes - `General`, `Ladies`, `SeniorCitizen`, `Tatkal`, `PremiumTatkal`. It also has another derived class `Divyaang` which in itself is a polymorphic hierarchy with 4 base classes - `Blind`, `OrthoHandicapped`, `Cancer`, `TB`.

- **Booking.cpp**  
This is the source file for the `Booking` class. Here, we first initialize few of the static variables. Then we implement all the constructors and member functions declared in `Booking.h`.

- **UnitTestBooking.cpp**  
This file contains the function body for the unit testing function of the `Booking` class.

- **Name.h**  
This is the header file for the `Name` class and contains the declarations of the data members of the `Name` class. 

- **Name.cpp**
This is the header file for the `Name` class and contains the declarations of all the data members, constructors and member functions of this class.

- **UnitTestName.cpp**  
This file contains the function body for the unit testing function  with all the test cases of the `Name` class.

- **Concessions.h**  
This is the header file for the `Concessions` class and contains the declarations of the data members of the `Concessions` class. `Concessions` is a base class with 4 derived classes modelled using ad-hoc polymorphism. These classes are - `GeneralConcessions`, `LadiesConcessions`, `SeniorCitizenConcessions` and `DivyaangConcessions`

- **Concessions.cpp**
This is the header file for the `Concessions` class and contains the declarations of all the data members, constructors and member functions of this class.

- **UnitTestConcessions.cpp**  
This file contains the function body for the unit testing function  with all the test cases of the `Concessions` class.

- **Gender.h**  
This is the header file for the `Gender` class and contains the declarations of the data members of the `Gender` class. `Gender` is a abstract base class with 2 concrete derived classes modelled using parametric polymorphism. These classes are - `Male` and `Female`.

- **Gender.cpp**
This is the header file for the `Gender` class and contains the declarations of all the data members, constructors and member functions of this class.

- **UnitTestGender.cpp**  
This file contains the function body for the unit testing function  with all the test cases of the `Gender` class.

- **Exceptions.h**  
This is the header file for the `Exceptions` class and contains the declarations of the data members of the `Exceptions` class. `Exceptions` class inherits from standard class `exception`. It has other derived classes like - `Bad_Date`, `Bad_Station`, `Bad_Booking`, `Bad_Railways`, and `Bad_Passenger`. Some of these also have further hierarchies for specific exceptional cases.

- **Exceptions.cpp**
This is the header file for the `Exceptions` class and contains the declarations of all the data members, constructors and member functions of this class.

- **Application.cpp**  
This is a test application file created to perform the application testing for the project covering various scenarios.

- **ApplicationTestGivenPositive.cpp**  
The already given application file illustrating various booking scenarios. We have added a few static constant initializations at the beginning which are necessary for the project to compile and run.

- **ApplicationTestGivenPositive.cpp**  
The already given application file illustrating various booking scenarios. We have added a few static constant initializations at the beginning which are necessary for the project to compile and run.

- **makefile**  
A simple makefile to compile and build the project.

## Compiler Used

We have used the GNU GCC compiler. The entire code is written in C++. The C++ standard followed is C++11. All libraries used are standard C++ libraries.

## Compilation and Build Instructions

To compile and build the project, ensure all the above listed files are in the same directory. Then navigate to that directory and run the following commands in the terminal:

```shell
$ make
$ ./rbs
```

Note that by default, the application file selected is `ApplicationPositive.cpp`. To change this, just pass the name of the application file which you want to use (without the .cpp extension) as an argument to the `make` command. For example, if you want to use the file `ApplicationNegative.cpp` as the application file, use the commands :

```shell
$ make APPFILE=ApplicationNegative
$ ./rbs
```

## Compilation and Build Instructions for Unit Testing the Individual Classes

- For unit testing the `Booking` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestBooking.cpp -o test
$ ./test
```

- For unit testing the `BookingCategory` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestBookingCategory.cpp -o test
$ ./test
```

- For unit testing the `BookingClass` class, use the following commands :

```shell
$ g++ -std=c++11 BookingClass.cpp UnitTestBookingClass.cpp -o test
$ ./test
```

- For unit testing the `Concession` hierarchy, use the following commands :

```shell
$ g++ -std=c++11 Concession.cpp Date.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Gender.cpp Name.cpp Booking.cpp Station.cpp Railways.cpp Exceptions.cpp UnitTestConcession.cpp -o test
$ ./test
```

- For unit testing the `Date` class, use the following commands :

```shell
$ g++ -std=c++11 Date.cpp Exceptions.cpp UnitTestDate.cpp -o test
$ ./test
```

- For unit testing the `Gender` class, use the following commands :

```shell
$ g++ -std=c++11 Gender.cpp UnitTestGender.cpp -o test
$ ./test
```

- For unit testing the `Name` class, use the following commands :

```shell
$ g++ -std=c++11 Name.cpp Exceptions.cpp UnitTestName.cpp -o test
$ ./test
```

- For unit testing the `Passenger` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp Gender.cpp Name.cpp Passenger.cpp BookingClass.cpp BookingCategory.cpp Concession.cpp Booking.cpp Exceptions.cpp UnitTestPassenger.cpp -o test
$ ./test
```

- For unit testing the `Railways` hierarchy, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Exceptions.cpp UnitTestRailways.cpp -o test
$ ./test
```

- For unit testing the `Station` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Exceptions.cpp UnitTestStation.cpp -o test
$ ./test
```