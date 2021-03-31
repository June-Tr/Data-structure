CC     = gcc
CFLAGS = -Wall

singly_list.o: Singly_list/singly_list.c Singly_list/singly_list.h
	$(CC) $(CFLAGS) -c -o Singly_list/singly_list.o  Singly_list/singly_list.c

:: this is a share object file {need to learn more about this}
singly_list.so: Singly_list/singly_list.c Singly_list/singly_list.h

singly_list_test: Singly_list/test.c Singly_list/singly_list.o
	make singly_list.o
	$(CC) $(CFLAGS) -o test Singly_list/test.c Singly_list/singly_list.o

clean_singly_list:
	rm -f Singly_list/singly_list.o test
