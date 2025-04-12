CC = g++
CFLAGS = -g -Wall -Wextra

default: driver

driver: driver.o BST.o
	$(CC) $(CFLAGS) -o driver driver.o BST.o

driver.o: driver.cpp BST.h
	$(CC) $(CFLAGS) -c driver.cpp

BST.o: BST.cpp BST.h
	$(CC) $(CFLAGS) -c BST.cpp

clean:
	$(RM) driver *.o *~