#!/bin/bash

# written by liujian, 2011.10.29

export BUILDDIR=`pwd`/lcc
if [ ! -d $BUILDDIR ]; then
   mkdir $BUILDDIR
fi

#make HOSTFILE=etc/linux.c lcc
make CC=gcc CFLAGS="-g -fprofile-arcs -ftest-coverage" LDFLAGS="-g -fprofile-arcs -ftest-coverage"  rcc 
