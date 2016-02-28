#!/bin/bash
CC_DIR=/home/coolbar/Desktop/tmp/lcc-4.1

### clean
if [ "$*" == "--clean" ]; then
   CLEAN_ENABLE=true
fi

#clean coverage data & report
rm -f $CC_DIR/lcc/*.gcda *.gcov
rm *.o

if [ "$CLEAN_ENABLE" = "true" ]; then
   exit 0
fi

# run
lcc -c -A -A test.c


