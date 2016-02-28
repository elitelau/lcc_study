#!/bin/bash

rm -f *.s *.o

export CC=gcc
${CC} -c a.c -S
${CC} -c b.c -S
mv a.s a.${CC}.s
mv b.s b.${CC}.s

export CC=lcc
${CC} -c a.c -S
${CC} -c b.c -S
mv a.s a.${CC}.s
mv b.s b.${CC}.s
