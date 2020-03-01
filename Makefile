a.out: A2_PES1201801972.o client.o
	gcc -g client.o A2_PES1201801972.o
client.o: client.c assignment_2.h
	gcc -c assignment_2.h client.c
A2_PES1201801972.o: assignment_2.h A2_PES1201801972.c
	gcc -c assignment_2.h A2_PES1201801972.c
clean:
	rm -f A2_PES1201801972.o client.0