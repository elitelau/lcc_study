#!/bin/bash
rm -f *.o *.s
lcc -c -S test1.c
lcc -c -S test2.c
