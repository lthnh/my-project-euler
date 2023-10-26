#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char const *ones[] = {"",     "one", "two",   "three", "four",
                      "five", "six", "seven", "eight", "nine"};
char const *teens[] = {"ten",      "eleven",  "twelve",  "thirteen",
                       "fourteen", "fifteen", "sixteen", "seventeen",
                       "eighteen", "nineteen"};
char const *tens[] = {"twenty", "thirty",  "forty",  "fifty",
                      "sixty",  "seventy", "eighty", "ninety"};
char const *large_numbers[] = {"hundred", "thousand"};
char const *const conjuction = "and";

size_t cv_one(int number) {
    printf("%s\n", ones[number]);
    return strlen(ones[number]);
}

size_t cv_ten(int number) {
    size_t len = 0;
    if (10 <= number && number < 20) {
        printf("%s\n", teens[number - 10]);
        len = strlen(teens[number - 10]);
    } else if (20 <= number && number < 100) {
        printf("%s", tens[number / 10 - 2]);
        len = strlen(tens[number / 10 - 2]) + cv_one(number % 10);
    }
    return len;
}

size_t cv_hundred(int number) {
    printf("%s%s", ones[number / 100], large_numbers[0]);
    size_t len = strlen(ones[number / 100]) + strlen(large_numbers[0]);
    int ten_part = number % 100;
    if (0 < ten_part && ten_part < 10) {
        printf("%s", conjuction);
        len += strlen(conjuction) + cv_one(ten_part);
    } else if (10 <= ten_part && ten_part < 100) {
        printf("%s", conjuction);
        len += strlen(conjuction) + cv_ten(ten_part);
    }
    return len;
}

size_t cv_arbitrary(int number) {
    if (1 <= number && number < 10) return cv_one(number);
    if (10 <= number && number < 100) return cv_ten(number);
    if (100 <= number && number < 1000) return cv_hundred(number);
    return 3 + strlen(large_numbers[1]);
}

int main(void) {
    size_t ans = 0;
    for (int i = 1; i <= 1000; ++i) ans += cv_arbitrary(i);
    printf("%lu\n", ans);
    return EXIT_SUCCESS;
}