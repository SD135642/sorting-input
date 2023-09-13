# sorting-input
This project consists of two main components: sort.c and quicksort.c. Together, they provide a program that performs sorting operations on different types of data (strings, integers, and doubles) using the quicksort algorithm.
Overview

## sort.c

This file contains the main program that is responsible for the sorting process. It takes input flags to determine the type of data (ints, doubles, or strings) and reads the input from a file or stdin. The sorted output is then printed to stdout.

### Usage

This program is designed to work in a Linux environment. To build, run the commands:

    cd <repository's directory> 
    make

To run this program, run the command:

    ./sort [-i|-d] [filename]

    -i: Specifies the input contains integers.
    -d: Specifies the input contains doubles.
    if no flag is supplied, the input is assumed to be strings
    filename: The file to sort. If no file is supplied, input is read from stdin.

## quicksort.c

This file provides the implementation of the quicksort algorithm and comparison functions for different data types.


### Usage
This program is designed to work in a Linux environment. To build, run the commands:

    This program is a dependency of sort.c and is compiled and ran at the same time.

Additional Notes

    If no file is provided, the program expects input from stdin.
