CC=g++

CFLAGS=-std=c++14 -g -c -Wall

all: Lab1_OOP

Lab1_OOP: main.o funcs.o
	$(CC) main.o funcs.o -o Lab1_OOP

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

funcs.o: funcs.cpp
	$(CC) $(CFLAGS) funcs.cpp

clean:
	rm -rf *.o Lab1_OOP
