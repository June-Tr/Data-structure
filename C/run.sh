#!/bin/bash
make singly_list_test
echo
echo
echo "Start-------------------------------------------------------------"
valgrind --leak-check=full ./test 
echo "End---------------------------------------------------------------"
echo
echo
make clean_singly_list
