#!/bin/bash

CC=lcc

rm -f *.o run.x

${CC} -P -c b.c
${CC} -P -c a.c
${CC} *.o -o run.x
./run.x
