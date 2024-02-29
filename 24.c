#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

void reverse(int *array, size_t index) {
    size_t slice_len = LENGTH - index;
    size_t t = slice_len / 2;
    for (size_t i = 0; i < t; ++i) {
        size_t a = index + i;
        size_t b = (LENGTH - 1) + index - a;
        swap(&array[a], &array[b]);
    }
}

void test_rev(void) {
    int *a = calloc(LENGTH, sizeof(int));
    for (int i = 0; i < LENGTH; ++i) {
        a[i] = i;
    }
    reverse(a, 6);
    for (size_t i = 0; i < 10; ++i) {
        printf("%d\n", a[i]);
    }
    free(a);
}

int main(void) {
    int a[LENGTH] = {0};
    for (int i = 0; i < LENGTH; ++i) {
        a[i] = i;
    }
    bool exhausted = false;
    int count = 1;
    while (!exhausted) {
        int k = 0;
        int l = 0;
        for (int i = LENGTH - 2; i >= 0; --i) {
            if (a[i] < a[i+1]) {
                k = i;
                break;
            } else if (i == 0) {
                exhausted = true;
            }
        }
        if (exhausted) break;
        for (int i = LENGTH - 1; i >= 0; --i) {
            if (i > k && a[i] > a[k]) {
                l = i;
                break;
            }
        }
        swap(&a[k], &a[l]);
        reverse(a, k+1);
        for (size_t i = 0; i < LENGTH; ++i) {
            printf("%d", a[i]);
        }
        printf("\n");
        ++count;
        if (count >= (int)1e6) break;
    }
    // test_rev();
    return 0;
}