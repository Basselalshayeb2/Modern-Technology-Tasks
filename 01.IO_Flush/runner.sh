#!/bin/bash

gcc index.c

echo "Running default scenario with fflush:"
./io_flush_program -d > output_1.txt 2>&1

echo "Running scenario with newline (\\n) addition:"
./io_flush_program -n > output_2.txt 2>&1

echo "Running scenario without fflush:"
./io_flush_program -s > output_3.txt 2>&1

echo "Running scenario with redirect to file:"
./io_flush_program -r > output_4.txt 2>&1

echo "Check output files for results."