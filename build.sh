#!/bin/bash
# Poor man's Makefile

gcc -O2 -Wall -I ./include -c -o ./build/main.o ./src/main.c 
gcc -O2 -Wall -I ./include -c -o ./build/state.o ./src/state.c 
gcc -O2 -Wall -I ./include -c -o ./build/task.o ./src/task.c 
gcc -O2 -Wall -I ./include -c -o ./build/utils.o ./src/utils.c 

gcc -lm -o ./build/weekleez $(dir build/*.o)
