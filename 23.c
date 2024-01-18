#define CVECTOR_LOGARITHMIC_GROWTH

#include "libs/c-vector/cvector.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct factor {
	int prime;
	int exp;
} factor;

cvector(factor) factrz(int a) {
    cvector(factor) res = NULL;
    factor factr = {2, 0};
    while (a % 2 == 0) {
        ++factr.exp;
        a /= 2;
    }
    if (factr.exp > 0) {
        cvector_push_back(res, factr);
    }
    int b = a;
    for (int d = 3; d * d <= b; d += 2) {
        if (a % d == 0) {
            factr = (factor){d, 0};
            while (a % d == 0) {
                ++factr.exp;
                a /= d;
            }
            cvector_push_back(res, factr);
        }
    }
    if (a > 1) {
        factr = (factor){a, 1};
        cvector_push_back(res, factr);
    }
    return res;
}

int comp(const void *a, const void *b) {
    int ia = *((int *)a);
    int ib = *((int *)b);
    if (a > b) {
        return 1;
    } else {
        return -1;
    }
    return 0;
}

cvector(int) dvsr(cvector_vector_type(factor) factors) {
    cvector(int) res = NULL;

    size_t n_factr = cvector_size(factors);
    int primes[n_factr];
    int exps[n_factr];
    memset(primes, 0, n_factr * sizeof(int));
    memset(exps, 0, n_factr * sizeof(int));
    int bound = 0;

    if (factors) {
        for (size_t i = 0; i < n_factr; ++i) {
            primes[i] = factors[i].prime;
            exps[i] = factors[i].exp;
            bound += factors[i].exp;
        }
    } else {
        cvector_push_back(res, 1);
        return res;
    }

    int exp_combs[n_factr];
    memset(exp_combs, 0, n_factr * sizeof(int));
    int sum = 0;
    while (sum < bound) {
        size_t i = 0;
        while (i < n_factr) {
            if (exp_combs[i] + 1 <= exps[i]) {
                ++exp_combs[i];
                break;
            } else {
                exp_combs[i] = 0;
                ++i;
            }
        }

        int prod = 1;
        for (size_t j = 0; j < n_factr; ++j) {
            prod *= (int)pow((double)primes[j], (double)exp_combs[j]);
        }
        cvector_push_back(res, prod);

        sum = 0;
        for (size_t j = 0; j < n_factr; ++j) {
            sum += exp_combs[j];
        }
    }

    if (res) {
        cvector_pop_back(res);
    }
    cvector_insert(res, 0, 1);
    qsort(res, cvector_size(res), sizeof(int), comp);
    return res;
}

bool isabundnt(int a) {
    bool res = false;

    cvector(factor) factors = factrz(a);
    cvector(int) divisors = dvsr(factors);

    int sum = 0;
    for (size_t i = 0; i < cvector_size(divisors); ++i) {
        sum += divisors[i];
    }

    if (sum > a) {
        res = true;
    }

    cvector_free(factors);
    cvector_free(divisors);
    return res;
}

int main(void) {
    bool check[28124] = {false};
    for (int i = 1; i < 28124; ++i) {
        if (!check[(size_t)i] && isabundnt(i)) {
            check[(size_t)i] = true;
            int n = 2;
            while (n * i <= 28123) {
                check[(size_t)(n * i)] = true;
                ++n;
            }
        }
    }
    // for (size_t i = 0; i < 28124; ++i) {
    //     if (check[i]) {
    //         printf("%lu\n", i);
    //     }
    // }
    bool sum_abundnt[28124] = {false};
    for (size_t i = 0; i < 28123; ++i) {
        if (check[i]) {
            for (size_t j = i; j < 28124; ++j) {
                if (check[j]) {
                    size_t sum = i + j;
                    if (sum < 28124 && !sum_abundnt[sum]) {
                        sum_abundnt[sum] = true;
                    }
                }
            }
        }
    }
    size_t total_non_sum_abundnt = 0;
    for (size_t i = 1; i < 28124; ++i) {
        if (!sum_abundnt[i]) {
            total_non_sum_abundnt += i;
            printf("%lu\n", i);
        }
        // if (i > 200) break;
    }
    printf("%lu\n", total_non_sum_abundnt);
    // cvector(factor) factors = factrz(45);
    // if (factors) {
    //     for (size_t i = 0; i < cvector_size(factors); ++i) {
    //         printf("%d %d\n", factors[i].prime, factors[i].exp);
    //     }
    // }
    // printf("\n");
    // cvector(int) divisors = dvsr(factors);
    // if (divisors) {
    //     for (size_t i = 0; i < cvector_size(divisors); ++i) {
    //         printf("%d\n", divisors[i]);
    //     }
    // }
    // printf("\n");
    // bool abund = isabundnt(23);
    // printf("%d\n", abund);
    // cvector_free(factors);
    // cvector_free(divisors);
    return 0;
}
