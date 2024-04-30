OBJS = zombie_Alzowaidi.o conga.o hw5_Alzowaidi_Mohammed.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

exe : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o exe


zombie_Alzowaidi.o: zombie_Alzowaidi.h zombie_Alzowaidi.cpp
	$(CC) $(CFLAGS) zombie_Alzowaidi.cpp

conga.o: conga.cpp conga.h zombie_Alzowaidi.cpp zombie_Alzowaidi.h linkedlist_Alzowaidi.hpp
	$(CC) $(CFLAGS) conga.cpp

hw5_Alzowaidi_Mohammed.o: hw5_Alzowaidi_Mohammed.cpp conga.h conga.cpp
	$(CC) $(CFLAGS) hw5_Alzowaidi_Mohammed.cpp
	
clean:
	\rm *.o *~ exe

tar:
	tar cfv p1.tar zombie_Alzowaidi.h zombie_Alzowaidi.cpp conga.h conga.cpp linkedlist_Alzowaidi.hpp \
		hw5_Alzowaidi_Mohammed.cpp 
