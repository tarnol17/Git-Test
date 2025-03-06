CC = g++
CFLAGS = -g -Wall -Wextra

default: Main

Main: main.o phonebook.o
	$(CC) $(CFLAGS) -o Main main.o phonebook.

main.o: main.cpp phonebook.h
	$(CC) $(CFLAGS) -c phonebook.cpp

clean:
	$(RM) Main *.o *~
