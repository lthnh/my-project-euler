#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool rd[1001];
int p[1001];

int main(void) {
    int r;
    int recur_len;
    int max_len = 0;
    int d = 0;
    for (int i = 1; i < 1000; ++i) {
        r = 1;
        recur_len = -1;
        memset(rd, false, 1001);
        memset(p, 0, 1001);
        printf("%d ", i);
        while (r != 0) {
            r = (r * 10) % i;
            ++recur_len;
            if (!rd[r]) {
                rd[r] = true;
            } else {
                break;
            }
        }
        if (r == 0) {
            printf(" this number doesn't have recurring cycle\n");
        } else {
            printf("%d \n", recur_len);
            if (recur_len > max_len) {
                max_len = recur_len;
                d = i;
            }
        }
    }
    printf("%d %d\n", d, max_len);
    return 0;
}