#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#define MAX_SIZE 3000


int main(void) {
    int expo = 0;
    while (true) {
        int n[MAX_SIZE] = {1};
        int n_ln = 1;
        printf("Exp: ");
        int t = scanf("%d", &expo);
        if (t <= 0) break;
        for (int i = 0; i < expo; ++i) {
            size_t cr_p = 0;
            int br = 0;
            while (cr_p < n_ln) {
                n[cr_p] = n[cr_p]*2 + br;
                br = br ? 0 : br;
                if (n[cr_p] > 9) {
                    int r = n[cr_p]%10;
                    int q = n[cr_p]/10;
                    n[cr_p++] = r;
                    br = q;
                    if (cr_p >= n_ln) ++n_ln;
                }
                else ++cr_p;
            }
        }
        int sum = 0;
        for (int i = n_ln-1; i >= 0; --i) {
            printf("%d", n[i]);
            sum += n[i];
        }
        printf("\n%d\n", sum);
    }
    return EXIT_SUCCESS;
}