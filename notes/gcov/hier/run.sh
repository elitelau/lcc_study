#!/bin/bash

CC=gcc
CFLAG="-g -fprofile-arcs -ftest-coverage"
EXE=run.x

if [ "$*" == "--clean" ]; then
   CLEAN_ENABLE=true
fi

#clean
rm -f comm/*.o *.o ${EXE}
rm -f comm/*.gcno comm/*.gcda *.gcno *.gcda

if [ "$CLEAN_ENABLE" = "true" ]; then
   exit 1
fi

#compile
${CC} ${CFLAG} -c comm/arith.c -o comm/arith.o
${CC} ${CFLAG} -c test.c -o test.o -I comm/
${CC} ${CFLAG} test.o comm/arith.o -o ${EXE}

#run
./${EXE}

# coverage 
gcov comm/arith.c -o comm/arith.o
