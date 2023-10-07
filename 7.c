#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <tgmath.h>

bool prime_check(unsigned number) {
    for (int i = 2; i < number; i++)
        if (number % i == 0)
            return false;
    return true;
}

int main (void) {
    const unsigned n = 10001;
    double natural_log_of_n = log(n);
    const unsigned long limit = round(n*(natural_log_of_n+log(natural_log_of_n)));
    unsigned factor = 2;
    unsigned long multiple_of_prime = 0;
    unsigned count_prime = 0;

    bool prime_arr[limit-2];
    memset(&prime_arr, true, limit-2);

    for (unsigned long i = 2; i < limit; i++) {
        if (prime_check(i) && (prime_arr[i-2])) {
            multiple_of_prime = factor*i;
            count_prime++;
            while (multiple_of_prime <= limit) {
                prime_arr[multiple_of_prime-2] = false;
                factor++;
                multiple_of_prime = factor*i;
            }
            printf("%u\n", i);
            if (count_prime>=n)
                break;
        }
    }
    return EXIT_SUCCESS;
}