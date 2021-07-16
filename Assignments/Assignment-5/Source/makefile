CC = g++ -std=c++11
APPFILE = ApplicationPositive

rbs: Station.o Railways.o Date.o Gender.o Name.o Passenger.o BookingClass.o BookingCategory.o Concession.o Booking.o Exceptions.o $(APPFILE).o
	$(CC) Station.o Railways.o Date.o Gender.o Name.o Passenger.o BookingClass.o BookingCategory.o Concession.o Booking.o Exceptions.o $(APPFILE).o -o rbs

Station.o: Station.cpp Station.h Railways.h
	$(CC) -c Station.cpp

Railways.o: Railways.cpp Railways.h Station.h
	$(CC) -c Railways.cpp

Date.o: Date.cpp Date.h
	$(CC) -c Date.cpp

Gender.o: Gender.cpp Gender.h
	$(CC) -c Gender.cpp

Name.o: Name.cpp Name.h
	$(CC) -c Name.cpp

Passenger.o: Passenger.cpp Passenger.h Date.h Gender.h Name.h BookingCategory.h
	$(CC) -c Passenger.cpp

BookingClass.o: BookingClass.cpp BookingClass.h
	$(CC) -c BookingClass.cpp

BookingCategory.o: BookingCategory.cpp BookingCategory.h Passenger.h
	$(CC) -c BookingCategory.cpp

Concession.o: Concession.cpp Concession.h Passenger.h BookingClass.h BookingCategory.h
	$(CC) -c Concession.cpp

Booking.o: Booking.cpp Booking.h Station.h Railways.h Date.h BookingClass.h BookingCategory.h Concession.h Passenger.h
	$(CC) -c Booking.cpp

Exceptions.o: Exceptions.cpp Exceptions.h
	$(CC) -c Exceptions.cpp

$(APPFILE).o: $(APPFILE).cpp Station.h Railways.h Date.h Gender.h Name.h Passenger.h BookingClass.h BookingCategory.h Concession.h Booking.h
	$(CC) -c $(APPFILE).cpp

clean: 
	rm *.o rbs