#include <stdio.h>

int main(void) {
    int i = 1;
    int sum = 1;
    int l = 1001;
    int pre = 1;
    while (i < l) {
        i += 2;
        for (int k = 1; k <= 4; ++k) {
            sum += pre + k*(i-1);
        }
        pre = pre + 4*(i-1);
    }
    printf("%d\n", sum);
    return 0;
}