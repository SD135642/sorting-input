void swap(void *a, void *b, size_t size);
int lomuto(void *array, int left, int right, size_t elem_sz,
                    int (*cmp)(const void*, const void*));
void quicksort_helper(void *array, int left, int right, size_t elem_sz,
                                int (*cmp)(const void*, const void*));

int int_cmp(const void *a, const void *b);

int dbl_cmp(const void *a, const void *b);

int str_cmp(const void *a, const void *b);

void quicksort(void *array, size_t len, size_t elem_sz, int (*cmp)(const void*, const void*));

