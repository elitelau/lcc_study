#!/bin/bash

echo "compile in lcc.."
lcc test.c -o run1.x
./run1.x

echo "compile in gcc.."
gcc test.c -o run2.x
./run2.x
