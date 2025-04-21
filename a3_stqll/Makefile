
#Makefile

CC=gcc
CFLAGS=
OBJS=
LIBS=-lm
all : linkedlisttest.out polarrtest.out poltest.out queuetest.out

linkedlisttest.out : linkedlisttest.o linkedlist.o
	$(CC) $(CFLAGS) -o linkedlisttest.out linkedlisttest.o linkedlist.o

polarrtest.out : polarrtest.o polynomial_arr.o
	$(CC) $(CFLAGS) -o polartest.out  polarrtest.o polynomial_arr.o $(LIBS)

poltest.out : poltest.o linkedlist.o polynomial_ll.o
	$(CC) $(CFLAGS) -o poltest.out linkedlist.o poltest.o polynomial_ll.o $(LIBS)

queuetest.out : queuetest.o queue.o
	$(CC) $(CFLAGS) -o queuetest.out queuetest.o queue.o

clean:
	rm *.o *.out
