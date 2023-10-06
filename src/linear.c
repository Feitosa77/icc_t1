#include "linear.h"

/* Vector */

Vector vector_create(int order)
{
    return malloc(sizeof(IR) * order);
}

void vector_destroy(Vector x)
{
    free(x);
}

void vector_print(Vector x, int order)
{
    for (int i = 0; i < order; ++i)
        ir_print(x[i]);
    printf("\n");
}

void vector_print_inf(Vector x, int order)
{
    for (int i = 0; i < order; ++i)
        printf("%lf ", x[i].a);
    printf("\n\n");
}

void vector_print_sup(Vector x, int order)
{
    for (int i = 0; i < order; ++i)
        printf("%lf ", x[i].b);
    printf("\n\n");
}

/* Matrix */

Matrix matrix_create(int i, int j)
{
    Matrix A = malloc(sizeof(IR *) * i);

    for (i = 0; i < j; ++i)
        A[i] = malloc(sizeof(IR) * j);

    return A;
}

void matrix_destroy(Matrix A, int i)
{
    while (i)
        free(A[--i]);

    free(A);
}

void matrix_print(Matrix A, int i, int j)
{
    for (int l = 0; l < i; ++l)
    {
        for (int k = 0; k < j; ++k)
            ir_print(A[l][k]);
        putchar('\n');
    }

    putchar('\n');
}

void matrix_print_inf(Matrix A, int i, int j)
{
    for (int l = 0; l < i; ++l)
    {
        for (int k = 0; k < j; ++k)
            printf("%lf ", A[l][k].a);
        putchar('\n');
    }

    putchar('\n');
}

void matrix_print_sup(Matrix A, int i, int j)
{
    for (int l = 0; l < i; ++l)
    {
        for (int k = 0; k < j; ++k)
            printf("%lf ", A[l][k].b);
        putchar('\n');
    }

    putchar('\n');
}
