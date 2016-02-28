#!/bin/bash

export LCC_SYM_DUMP_ENABLE=true
lcc -c -A -A test.c
