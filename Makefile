CC=gcc
CFLAGS=-c
RFLAGS=-f
a.out: A2_PES1201801972.o client.o
	$(CC) client.o A2_PES1201801972.o
client.o: client.c assignment_2.h
	$(CC) $(CFLAGS) assignment_2.h client.c
A2_PES1201801972.o: assignment_2.h A2_PES1201801972.c
	$(CC) $(CFLAGS) assignment_2.h A2_PES1201801972.c
clean:
	rm $(RFLAGS) A2_PES1201801972.o client.o assignment_2.h.gch