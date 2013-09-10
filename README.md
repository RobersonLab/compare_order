compare_order
=============

## Purpose
A simple C++ program for comparing the read identifiers of two sequencing files (Illumina formatted single-line or FASTQ format). It reads the files line by line together and compares their read identifiers. The goal is to confirm that reads are ordered the same in each file. The identifier must be separated from index/pair by a # character, e.g. HWIFAKE:1:1:1:1#0/1.

## Compiling

### Linux
    make
	make install

### Windows
    g++ -o compare_order -O3 compare_order.cpp
	
### Running
Requires specifying three parameters:
--format scarf|fastq
--file1 filename
--file2 filename

    compare_order --format scarf --file1 mate_1.txt --file2 mate_2.txt
	compare_order --format fastq --file1 mate_1.fq --file2 mate_2.fq
