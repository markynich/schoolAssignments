#
#
CC=g++ -std=c++11  
#
CFLAGS = -c -Wall -I/usr/include/mysql 
#LFLAGS = -L/usr/lib/mysql -lmysqlclient
LFLAGS =  

all: winemain

winemain: winemain.o wine.o printMeFirst.o
	$(CC) winemain.o wine.o   printMeFirst.o -o winemain $(LFLAGS)

winemain.o: winemain.cpp
	$(CC) $(CFLAGS) winemain.cpp

wine.o: wine.cpp wine.h
	$(CC) $(CFLAGS) wine.cpp


printMeFirst.o: printMeFirst.cpp  
	$(CC) $(CFLAGS) printMeFirst.cpp

clean:
	rm *.o winemain

run:
	./winemain  
