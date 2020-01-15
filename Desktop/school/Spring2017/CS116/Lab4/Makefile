#
#
CC=g++
#
CFLAGS = -c -Wall -I/usr/include/mysql 
#LFLAGS = -L/usr/lib/mysql -lmysqlclient
LFLAGS =  

all: bankmain

bankmain: bankmain.o account.o printMeFirst.o
	$(CC) bankmain.o account.o printMeFirst.o -o bankmain 
#$(LFLAGS)

bankmain.o: bankmain.cpp
	$(CC) $(CFLAGS) bankmain.cpp

account.o: account.cpp account.h
	$(CC) $(CFLAGS) account.cpp

printMeFirst.o: printMeFirst.cpp  printMeFirst.h
	$(CC) $(CFLAGS) printMeFirst.cpp

clean:
	rm *.o bankmain

run:
	./bankmain
