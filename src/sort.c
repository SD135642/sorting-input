#include <errno.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quicksort.h"

#define MAX_STRLEN 64
#define MAX_ELEMENTS 1024

void print_usage(char *program_name) {
    printf("Usage: %s [-i|-d] [filename]\n", program_name);
    printf("    -i: Specifies the input contains ints.\n");
    printf("    -d: Specifies the input contains doubles.\n");
    printf("    filename: The file to sort. If no file is supplied, input is read from\n    stdin\n");
    printf("    No flags defaults to sotring strings.\n");
}

void print_strarr(char input[][MAX_STRLEN + 1], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s", input[i]);
    }
}

void print_intarr(int input[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d\n", input[i]);
    }
}

void print_dblarr(double input[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%lf", input[i]);
    }
}

int main(int argc, char **argv) {
    int opt;
    opterr = 0;
    int flag_count = 0;
    char prev_flag = 's';
    char *filename = NULL;
    while ((opt = getopt(argc, argv, ":id")) != -1) {
        switch (opt) {
            case 'i':
                if (prev_flag != 'i') {
                    flag_count++;
                }
                prev_flag = 'i';
                break;
            case 'd':
                if (prev_flag != 'd') {
                    flag_count++;
                }
                prev_flag = 'd';
                break;
            case '?':
                fprintf(stderr, "Error: Unknown option '-%c' received.\n", optopt);
                print_usage(argv[0]);
                return EXIT_FAILURE;
        }
    }
    if (flag_count > 1) {
        fprintf(stderr, "Error: Too many flags specified.\n");
        return EXIT_FAILURE;
    }
    if ((argc - optind) > 1) {
        fprintf(stderr, "Error: Too many files specified.\n");
        return EXIT_FAILURE;
    }
    filename = argv[optind];
    FILE *fp = fopen(filename, "r");
    if (filename != NULL) {
        if (fp == NULL) {
            fprintf(stderr, "Error: Cannot open '%s'. %s.\n", filename, strerror(errno));
            return EXIT_FAILURE;
        }
    } else {
        fp = stdin;
    }

    if (prev_flag == 's') {
        char input[MAX_ELEMENTS][MAX_STRLEN + 1];
        int array_size = 0;
        while (!feof(fp)) {
            if(!fgets(input[array_size++], MAX_STRLEN + 1, fp)) {
                fprintf(stderr, "Error: Cannot read from '%s'. %s.\n", filename, strerror(errno));
                exit(EXIT_FAILURE);
            }
        }
        array_size--;
        quicksort(input, array_size, MAX_STRLEN + 1, str_cmp);
        print_strarr(input, array_size);
    } else if (prev_flag == 'i') {
        int input[MAX_ELEMENTS];
        int array_size = 0;
        char buf[MAX_STRLEN + 1];
        while (!feof(fp)) {
            if(!fgets(buf, MAX_STRLEN + 1, fp)) {                
                fprintf(stderr, "Error: Cannot read from '%s'. %s.\n", filename, strerror(errno));
                exit(EXIT_FAILURE);
            }
            input[array_size++] = atoi(buf);
        }
        array_size--;
        quicksort(input, array_size, sizeof(int), int_cmp);
        print_intarr(input, array_size);
    } else {
        double input[MAX_ELEMENTS];
        int array_size = 0;
        char buf[MAX_STRLEN + 1];
        while (!feof(fp)) {
            if(!fgets(buf, MAX_STRLEN + 1, fp)) {                
                fprintf(stderr, "Error: Cannot read from '%s'. %s.\n", filename, strerror(errno));
                exit(EXIT_FAILURE);
            }
            input[array_size++] = atof(buf);
        }
        array_size--;
        quicksort(input, array_size, sizeof(double), dbl_cmp);
        print_dblarr(input, array_size);
    }
    if (filename != NULL) {
        fclose(fp);
    }
}









