#!/bin/bash
CC_DIR=/home/coolbar/Desktop/tmp/lcc-4.1

### clean
if [ "$*" == "--clean" ]; then
   CLEAN_ENABLE=true
fi

#clean coverage data & report
rm -f $CC_DIR/lcc/*.gcda *.gcov *.sym *.dot *.png
rm -f *.o *.s

if [ "$CLEAN_ENABLE" = "true" ]; then
   exit 0
fi

# variable
export LCC_SYM_DUMP_ENABLE=true
export LCC_DAG_DUMP_ENABLE=true

# run
lcc -c -S -A -A test.c

# coverage measure
cd $CC_DIR
gcov src/dag.c -o lcc/dag.o
gcov src/types.c -o lcc/types.o
gcov src/sym.c -o lcc/sym.o
gcov src/gen.c -o lcc/gen.o
gcov src/expr.c -o lcc/expr.o
gcov src/decl.c -o lcc/decl.o

cd -
mv $CC_DIR/dag.c.gcov .
mv $CC_DIR/types.c.gcov .
mv $CC_DIR/sym.c.gcov .
mv $CC_DIR/gen.c.gcov .
mv $CC_DIR/expr.c.gcov .
mv $CC_DIR/decl.c.gcov .
