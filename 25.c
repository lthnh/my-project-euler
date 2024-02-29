#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *s = calloc(3000, sizeof(char));
    mpz_t f1, f2, f3;
    mpz_inits(f1, f2, f3, NULL);
    mpz_set_si(f1, 1);
    mpz_set_si(f2, 1);
    mpz_set_si(f3, 0);
    int count = 2;
    while (strlen(s) < 1000) {
        ++count;
        mpz_add(f3, f1, f2);
        gmp_printf("%d %Zd\n", count, f3);
        mpz_get_str(s, 10, f3);
        mpz_set(f2, f1);
        mpz_set(f1, f3);
    }
    mpz_clears(f1, f2, f3, NULL);
    free(s);
    return 0;
}