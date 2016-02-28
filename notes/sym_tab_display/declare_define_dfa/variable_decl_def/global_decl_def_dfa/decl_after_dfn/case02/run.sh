#!/bin/bash
CC=gcc
rm -f *.o run.x

${CC} -c main.c
${CC} -c a.c
${CC} *.o -o run.x
./run.x
