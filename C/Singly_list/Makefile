CC     = gcc
CFLAGS = -Wall

singly_list.o: singly_list.c singly_list.h
	$(CC) $(CFLAGS) -c -o singly_list.o  singly_list.c

:: this is a share object file {need to learn more about this}
singly_list.so: singly_list.c singly_list.h

singly_list_test: test.c singly_list.o
	make singly_list.o
	$(CC) $(CFLAGS) -o test test.c

clean_singly_list:
	rm -f singly_list.o *.exe
