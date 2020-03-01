CC=gcc
CFLAGS=-c
RFLAGS=-f
a.out: BinaryCounter.o client.o
	$(CC) client.o BinaryCounter.o
client.o: client.c assignment_2.h
	$(CC) $(CFLAGS) assignment_2.h client.c
BinaryCounter.o: assignment_2.h BinaryCounter.c
	$(CC) $(CFLAGS) assignment_2.h BinaryCounter.c
clean:
	rm $(RFLAGS) BinaryCounter.o client.o assignment_2.h.gch
