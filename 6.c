#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

unsigned long diff(size_t n, int* arr_num) {
    unsigned long sosqr = 0, sqros = 0, db = 0;
    for (size_t i = 0; i < n; i++) {
        sqros += arr_num[i];
        sosqr += pow(arr_num[i], 2);
    }
    sqros = pow(sqros, 2);
    db = fdim(sqros, sosqr);
    return db;
}

void main(void) {
    int* arr = calloc(100, sizeof(int));
    for (int i = 1; i<= 100; i++) {
        arr[i-1] = i;
    }
    
    printf("%ld", __STDC_VERSION__);
    printf("\n%ul", diff(100, arr));
}