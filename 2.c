#include <stdio.h>

#define MAX_CAP 4000000

int main(void)
{
    unsigned long a = 1, b = 1, c = 0, sum = 0;
    while (a < MAX_CAP) {
        c = b;
        b = a;
        a += c;
        if (a % 2 == 0)
            sum += a;
    }
    printf("%d", sum);
    return 0;
}