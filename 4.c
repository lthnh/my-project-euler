#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check_palindrome(unsigned long long x)
{
    // Turn number into string for ease of checking.
    size_t str_length = snprintf(NULL, 0, "%u", x);
    char *number_as_str = calloc(str_length + 1, sizeof(char));
    snprintf(number_as_str, str_length + 1, "%u", x);

    // Check to see if the number is a palindrome number.
    size_t compare_caps = str_length / 2;
    for (size_t i = 0; i < compare_caps; i++)
    {
        if (number_as_str[i] != number_as_str[str_length - 1 - i])
            return false;
    }
    free(number_as_str);
    return true;
}

int main(void)
{
    unsigned long long max = 0;
    for (unsigned i = 999; i >= 100; i--)
    {
        for (unsigned j = i; j >= 100; j--)
        {
            unsigned long long sum = i * j;
            if ((check_palindrome(sum)) && (sum>max))
            {
                max = sum;
            }
        }
    }
    printf("%llu", max);
    return EXIT_SUCCESS;
}