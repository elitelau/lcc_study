#!/bin/bash


if [ $# -gt 0 ]; then
   if [ "$1" = "--init" ]; then
      INITILIZER=true
   fi
fi
if [ "$INITILIZER" = "true" ]; then
   # int a; => int a = 3;
   if cat a.c | grep -q "int[ ][ ]*a[ ]*;"; then
      sed -i 's/int\([ ][ ]*\)a\([ ]*\);/int\1a\2=3;/g' a.c 
   fi
   if cat b.c | grep -q "int[ ][ ]*a[ ]*;"; then
      sed -i 's/int\([ ][ ]*\)a\([ ]*\);/int\1a\2=3;/g' b.c 
   fi
else   
   # int a = 3; => int a;
   if cat a.c | grep -q "int[ ][ ]*a[ ]*=[ ]*[0-9][0-9]*;"; then  
      sed -i 's/int\([ ][ ]*\)a\([ ]*\)=\([ ]*\)\([0-9][0-9]*\);/int\1a;/g' a.c 
   fi
   if cat b.c | grep -q "int[ ][ ]*a[ ]*=[ ]*[0-9][0-9]*;"; then  
      sed -i 's/int\([ ][ ]*\)a\([ ]*\)=\([ ]*\)\([0-9][0-9]*\);/int\1a;/g' b.c 
   fi
fi

lcc a.c -c
lcc b.c -c
lcc a.o b.o -o run.x
