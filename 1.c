#include <stdio.h>

#define range 1000

int main(void)
{
    int sum = 0;
    for (int i = 1; i < range; i++)
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    printf("%d", sum);
    return 0;
}