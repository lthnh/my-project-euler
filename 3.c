#include <stdio.h>
#include <stdbool.h>

void read_input(unsigned long long *number)
{
    printf("Enter the number needed to find the largest prime factor: ");
    scanf("%llu", number);
}


bool check(unsigned long long *number) {
    if (*number == 1)
        return true;
    else 
        return false;
}

unsigned long long largest_prime_factor(unsigned long long *number)
{
    while (*number%2 == 0)  //Chương trình hơi bị nghịch lý ở khúc này. Giả dụ nếu số được nhập vào là 2 thì factor sẽ là chính nó.
        *number /= 2;       //Nếu nhập vào những số rất lớn và bản thân nó là số nguyên tố thì lại trả về factor nhỏ hơn nó chứ không phải bản thân nó.
    if (check(number))
        return 2;

    while (*number%3 == 0)
        *number /= 3;
    if (check(number))
        return 3;

    unsigned long long i = 1, factor = 0;
    while (!check(number)) {    
        factor = 6*i-1;
        while (*number%factor == 0)
            *number /= factor;
        if (check(number)) return factor;
        factor = 6*i+1;
        while (*number%factor == 0)
            *number /= factor;
        if (check(number)) return factor;
        i++;
    }
}

int main()
{
    unsigned long long number0 = 0;
    read_input(&number0);
    number0 = largest_prime_factor(&number0);
    printf("%llu", number0);
    return 0;
}