#!/bin/bash
CC_DIR=/home/coolbar/Desktop/tmp/lcc-4.1

### clean
if [ "$*" == "--clean" ]; then
   CLEAN_ENABLE=true
fi

#clean coverage data & report
rm -f $CC_DIR/lcc/*.gcda *.gcov *.sym *.dot
rm *.o

if [ "$CLEAN_ENABLE" = "true" ]; then
   exit 0
fi

# variable
export LCC_SYM_DUMP_ENABLE=true
export LCC_DAG_DUMP_ENABLE=true

# run
lcc -c -A -A test.c

# coverage measure
cd $CC_DIR
gcov src/dag.c -o lcc/dag.o
gcov src/sym.c -o lcc/sym.o
gcov src/gen.c -o lcc/gen.o

cd -
mv $CC_DIR/dag.c.gcov .
mv $CC_DIR/sym.c.gcov .
mv $CC_DIR/gen.c.gcov .
