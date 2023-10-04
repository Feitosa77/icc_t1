#include "linear.h"

/* Vector */

Vector vector_create(int order) {
    return malloc(sizeof (IR) * order);
}

void vector_destroy(Vector x) {
    free(x);
}

void vector_print(Vector x, int order) {
    for (int i = 0; i < order; ++i)
        ir_print(x[i]);
    printf("\n\n");
}

/* Matrix */

Matrix matrix_create(int i, int j) {
    Matrix A = malloc(sizeof (IR*) * i);

    for (i = 0; i < j; ++i)
        A[i] = malloc(sizeof (IR) * j);

    return A;
}

void matrix_destroy(Matrix A, int i) {
    while (i)
        free(A[--i]);

    free(A);
}

void matrix_print(Matrix A, int i, int j) {
    for (int l = 0; l < i; ++l) {
        for(int k = 0; k < j; ++k)
            ir_print(A[l][k]);
        putchar('\n');
    }
    
    putchar('\n');
}

