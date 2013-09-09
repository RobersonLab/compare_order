compare_order
=============

## Purpose
A simple C++ program for comparing the read identifiers of two Illumina formatted (single-line) sequencing files. Reads the files together line by line and compares their read identifiers. The goal is to confirm that reads are ordered the same in each file. Relies on the data being single-line format, and for the identifier to be separated from index/pair by a # (e.g. HWIFAKE:1:1:1:1#0/1).

## Compiling

### Linux
    make
	make install

### Windows
    g++ -o compare_order -O3 compare_order.cpp
	
### Running
compare_order mate_1.txt mate_2.txt
