CC = g++ -std=c++11
APPFILE = ApplicationTest
CFLAGS = 

rbs: Station.o Railways.o Date.o BookingClasses.o Booking.o $(APPFILE).o
	$(CC) $(CFLAGS) Station.o Railways.o Date.o BookingClasses.o Booking.o $(APPFILE).o -o rbs

Station.o: Station.cpp Station.h Railways.h
	$(CC) $(CFLAGS) -c Station.cpp

Railways.o: Railways.cpp Railways.h Station.h
	$(CC) $(CFLAGS) -c Railways.cpp

Date.o: Date.cpp Date.h
	$(CC) $(CFLAGS) -c Date.cpp

BookingClasses.o: BookingClasses.cpp BookingClasses.h
	$(CC) $(CFLAGS) -c BookingClasses.cpp

Booking.o: Booking.cpp Booking.h Station.h Railways.h Date.h BookingClasses.h
	$(CC) $(CFLAGS) -c Booking.cpp

$(APPFILE).o: $(APPFILE).cpp Station.h Railways.h Date.h BookingClasses.h Booking.h
	$(CC) $(CFLAGS) -c $(APPFILE).cpp

clean: 
	rm *.o rbs 