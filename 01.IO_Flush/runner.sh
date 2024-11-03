#!/bin/bash

gcc -o program index.c

echo "Running default scenario with fflush:"
./program -d > output_1.txt 2>&1

echo "Running scenario with newline (\\n) addition:"
./program -n > output_2.txt 2>&1

echo "Running scenario without fflush:"
./program -s > output_3.txt 2>&1

echo "Running scenario with redirect to file:"
./program -r > output_4.txt 2>&1

echo "Check output files for results."