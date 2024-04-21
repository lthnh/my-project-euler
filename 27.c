#include <stdio.h>
#include <stdbool.h>

#define quad(n, a, b) n*n + a*n + b

bool is_prime(int n) {
    bool r = false;
    if (n < 0) return r;
    if (n == 2 || n == 3 || n == 5 || n == 7) {
        r = true;
    } else {
        for (int i = 2; i <= n/2; ++i) {
            if (n%i == 0) return r;
        }
        r = true;
    }
    return r;
}

int main(void) {
    int r, n;
    int max_p = 0;
    int ma = 0;
    int mb = 0;
    for (int a = -999; a < 1000; ++a) {
        for (int b = -999; b < 1000; ++b) {
            n = 0;
            r = quad(n, a, b);
            while (is_prime(r)) {
                ++n;
                r = quad(n, a, b);
            }
            if (n > max_p) {
                max_p = n;
                ma = a;
                mb = b;
            }
        }
    }
    printf("%d %d %d %d\n", ma, mb, ma*mb, max_p);
    return 0;
}
