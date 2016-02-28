#!/bin/bash

export LCC_SYM_DUMP_ENABLE=true
lcc -c -A -A test1.c
lcc -c -A -A test2.c
lcc -c -A -A test3.c
