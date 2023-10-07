#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned long long factorial(unsigned x)
{
    unsigned long long result = 1;
    for (int i = 2; i <= x; i++)
    {
        result *= i;
    }
    return result;
}

bool check_prime(unsigned long long x)
{
    if ((factorial(x-1) + 1) % x == 0) //Check prime number using Wilson's theorem.
        return true;
    else
        return false;
}

unsigned long long common_factor(unsigned long long x, unsigned long long y)
{
    unsigned long long cap = 0;
    if (x<y) 
        cap = x;
    else
        cap = y;
    for (unsigned long long i = 2; i <= cap; i++)
    {
            if ((check_prime(i))
                    && (x % i == 0)
                        && (y % i == 0))
                return i;
    }
    return 1;
}

int main(void)
{
    unsigned long long x = 1, temp_i = 0, temp_x = 0, temp_factor = 0;
    for (unsigned i = 2; i <= 20; i++)
    {
        temp_i = i;
        temp_x = x;
        while (common_factor(temp_x, temp_i) != 1)
        {
            temp_factor = common_factor(temp_x, temp_i);
            temp_i /= temp_factor;
            temp_x /= temp_factor;
        }
        if (temp_i > 1) x *= temp_i;
    }
    printf("%llu", x);
    return EXIT_SUCCESS;
}