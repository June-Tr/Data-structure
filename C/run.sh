#!/bin/bash
make test
echo
echo
echo "Start-------------------------------------------------------------"
valgrind --leak-check=full -s ./test
echo "End---------------------------------------------------------------"
echo
echo
make clean_test
