#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main(int argc, char **argv) {
    unsigned long long matrix[20][20] = {0};
    char *filename = argv[1];
    FILE *input = fopen(filename, "r");
    char *input_buffer = calloc(MAX_LENGTH, sizeof(char));
    for (size_t i = 0; i < 20; ++i) {
        char *endptr = NULL;
        size_t j = 0;
        input_buffer = fgets(input_buffer, MAX_LENGTH, input);
        char *input_element = strtok(input_buffer, " \n");
        matrix[i][j] = strtoull(input_element, &endptr, 10);
        while (input_element = strtok(NULL, " \n")) {
            ++j;
            matrix[i][j] = strtoull(input_element, &endptr, 10);
        }
    }
    free(input_buffer);
    for (size_t i = 0; i < 20; ++i) {
        for (size_t j = 0; j < 20; ++j)
            printf("%llu ", matrix[i][j]);
        printf("\n");
    }
    unsigned long long count = 0;
    unsigned long long product[8];
    unsigned long long max_product = 0;
    for (size_t i = 3; i < 17; ++i)
        for (size_t j = 3; j < 17; ++j) {
            for (size_t k = 0; k < 8; ++k)
                product[k] = 1;
            for (size_t k = 0; k < 4; ++k) {
                product[0] *= matrix[i-k][j]; // up
                product[1] *= matrix[i+k][j]; // down
                product[2] *= matrix[i][j-k]; // left
                product[3] *= matrix[i][j+k]; // right
                product[4] *= matrix[i-k][j-k]; // north west
                product[5] *= matrix[i-k][j+k]; // north east
                product[6] *= matrix[i+k][j+k]; // south east
                product[7] *= matrix[i+k][j-k]; // south west
            }
            for (size_t k = 0; k < 8; ++k)
                if (max_product < product[k])
                    max_product = product[k];
        }
    printf("%llu\n", max_product);
    return EXIT_SUCCESS;
}