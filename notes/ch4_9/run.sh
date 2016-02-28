#!/bin/bash

RUN_NAME=run.x
CC=lcc

${CC} *.c -DDEMO -o ${RUN_NAME}
./${RUN_NAME}

${CC} *.c -o ${RUN_NAME}
./${RUN_NAME}
