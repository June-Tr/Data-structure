CC     = gcc
CFLAGS = -Wall

singly_list.o: Singly_list/singly_list.c Singly_list/singly_list.h
	$(CC) $(CFLAGS) -c -o Singly_list/singly_list.o  Singly_list/singly_list.c

dynamic_array.o: Dynamic_array/dynamic_array.c Dynamic_array/dynamic_array.h
	$(CC) $(CFLAGS) -c -o Dynamic_array/dynamic_array.o Dynamic_array/dynamic_array.c

test: Dynamic_array/test.c Dynamic_array/dynamic_array.o
	$(CC) $(CFLAGS) -g -o test Dynamic_array/test.c Dynamic_array/dynamic_array.o

clean_singly_list:
	rm -f Singly_list/singly_list.o

clean_dynamic_array:
	rm -f Dynamic_array/dynamic_array.o

clean_test:
	make clean_dynamic_array
	rm -f test
