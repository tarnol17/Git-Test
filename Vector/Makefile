CC = g++
CFLAGS = -g -Wall -Wextra

default: Main

Main: main.o Vector.o
	$(CC) $(CFLAGS) -o Main main.o Vector.o
main.o: main.cpp Vector.h
	$(CC) $(CFLAGS) -c main.cpp
Vector.o: Vector.cpp Vector.h
	$(CC) $(CFLAGS) -c Vector.cpp
clean:
	$(RM) Main *.o *~
