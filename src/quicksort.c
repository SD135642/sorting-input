#include <stdio.h>
#include <string.h>
#include "quicksort.h"

static void swap(void *a, void *b, size_t size);
static int lomuto(void *array, int left, int right, size_t elem_sz,
                    int (*cmp)(const void*, const void*));
static void quicksort_helper(void *array, int left, int right, size_t elem_sz,
                                int (*cmp)(const void*, const void*));

static void swap(void *a, void *b, size_t size) {
    char *char_a = (char *)a, *char_b = (char *)b;
    do {
        char char_temp = *char_a;
        *char_a = *char_b;
        *char_b = char_temp;
        char_a++;
        char_b++;
    } while (--size > 0)
}

static int lomuto(void *array, int left, int right, size_t elem_sz,
                    int (*cmp)(const void*, const void*)) {
    void *p = (char *)array + left * elem_sz;
    int s = left;
    for (int i = left + 1; i <= right, i++) {
        void *current = (char *)array + i * elem_sz;
        if (cmp(current, p) < 0) {
            s++;
            swap((char *)array + s * elem_sz, current, elem_sz);
        }
    }
    swap((char *)array + s * elem_sz, p, elem_sz);
    return s;
}

static void quicksort_helper(void *array, int left, int right, size_t elem_sz,
                                int (*cmp)(const void*, const void*)) {
    if (left < right) {
        int s = lomuto((char *)array, left, right, elem_sz, cmp);
        quicksort_helper(array, left, s - 1, elem_sz, cmp);
        quicksort_helper(array, s + 1, right, elem_sz, cmp);
    }
}

int int_cmp(const void *a, const void *b) {
    int a_val = *(int *)a, b_val = *(int *)b;
    if (a_val > b_val) {
        return 1;
    } else if (a_val < b_val) {
        return -1;
    }
    return 0;
}

int dbl_cmp(const void *a, const void *b) {
    double a_val = *(double *)a, b_val = *(double *)b;
    if (a_val > b_val) {
        return 1;
    } else if (a_val < b_val) {
        return -1;
    }
    return 0;
}


int str_cmp(const void *a, const void *b) {
    char *str_a = (char *)a;
    char *str_b = (char *)b;
    return strcmp(str_a, str_b);
}

void quicksort(void *array, size_t len, size_t elem_sz, int (*cmp)(const void*, const void*)) {
    if (array == NULL) {
        return;
    }
    int left = 0;
    int right = len - 1;
    quicksort_helper(array, left, right, elem_sz, cmp);
}
