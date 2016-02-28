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
export LCC_SYM_DUMP_DETAIL=true
#export LCC_DAG_DUMP_ENABLE=true

# run
lcc -c -A -A test.c

# coverage measure
cd $CC_DIR
gcov src/decl.c -o lcc/decl.o
gcov src/print_dag.c -o lcc/print_dag.o
gcov src/main.c -o lcc/main.o
gcov src/pass2.c -o lcc/pass2.o

cd -
mv $CC_DIR/print_dag.c.gcov .
mv $CC_DIR/decl.c.gcov .
mv $CC_DIR/main.c.gcov .
mv $CC_DIR/pass2.c.gcov .
