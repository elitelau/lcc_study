#!/bin/bash
DIR=`pwd`
cd ..

CC_DIR=/home/coolbar/Desktop/tmp/lcc-4.1

#clean coverage data
rm -f $CC_DIR/lcc/*.gcda

# run
lcc -c -A -A test1.c

# coverage measure
cd $CC_DIR
gcov src/decl.c -o lcc/decl.o
cd $DIR
mv $CC_DIR/decl.c.gcov .
