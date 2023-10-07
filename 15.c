#include <stdio.h>
#include <stdlib.h>

int main(void) {
    unsigned n;
    long long unsigned p_cnt = 1;
    printf("N: ");
    scanf("%u", &n);
    for (unsigned i = 0; i < n; ++i)
        p_cnt = p_cnt * (n*2-i) / (i+1);
    printf("%llu\n", p_cnt);
    return EXIT_SUCCESS;
}