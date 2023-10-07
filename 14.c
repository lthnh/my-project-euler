#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LIMIT 1e6

uint64_t collazt_sqnc_gn_ln(uint64_t sd) {
    uint64_t sqnc_ln = 1;
    while (sd>1) {
        if (sd%2==0)
            sd /= 2;
        else
            sd = 3*sd+1;
        ++sqnc_ln;
    }
    return sqnc_ln;
}

int main(void) {
    uint64_t sd = 2, max_ln = 1;
    for (uint64_t i = 3; i<(uint64_t)LIMIT; ++i) {
        uint64_t sqnc_ln = collazt_sqnc_gn_ln(i);
        if (sqnc_ln>max_ln) {
            sd = i;
            max_ln = sqnc_ln;
        }
        printf("%lu %lu\n", sd, sqnc_ln);
    }
    printf("%lu\n", sd);
    return EXIT_SUCCESS;
}