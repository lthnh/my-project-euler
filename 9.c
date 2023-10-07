#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>
#include <stdbool.h>

bool check_even(unsigned x) {
    if (x%2 == 0)
        return true;
    return false;
}

bool check_coprime(unsigned x, unsigned y) {
    if (x==y)
        return false;
    else if (x==1 || y==1)
        return true;
    unsigned min = x>y ? x : y;
    for (unsigned i = 2; i<=min; i++) {
        if (x%i==0 && y%i==0)
            return false;
    }
    return true;
}

void bubble_sort(int *arr) {
    int t = 0;
    if (arr[0]>arr[1]) {
        t = arr[0];
        arr[0] = arr[1];
        arr[1] = t;
    }
    if (arr[1]>arr[2]) {
        t = arr[1];
        arr[1] = arr[2];
        arr[2] = t;
    }
}

int main(void) {
    unsigned i = 2;
    unsigned a = 0, b = 0, c = 0;
    unsigned k = 1;
    unsigned sum = 0;
    int arr[3] = {0};
    bool found = false, stop = false;
    while (!found) {
        for (unsigned j = 1; j < i; j++)
            if (check_coprime(i,j) && (check_even(i) || check_even(j))) {
                a = pow(i,2) - pow(j,2);
                b = 2*i*j;
                c = pow(i,2) + pow(j,2);
                if (a>=1000 && b>=1000 && c>=1000) {
                    printf("Can't find Pythagorean triple matching criteria.\n");
                    stop = true;
                    break;
                }
                arr[0] = a;
                arr[1] = b;
                arr[2] = c;
                bubble_sort(arr);
                // printf("\n%u %u\n", j, i);
                printf("%u %u %u\n", arr[0], arr[1], arr[2]);
                sum = a+b+c;
                while (sum*k < 1000) {
                    k++;
                }
                if (sum*k == 1000) {
                    printf("%u %u %u\n", k*a, k*b, k*c);
                    printf("%lu\n", (unsigned long) pow(k,3)*a*b*c);
                    found = true;
                    break;
                }
                else {
                    k = 1;
                }
            }
        if (stop) break;
        i++;
    }
    return EXIT_SUCCESS;
}