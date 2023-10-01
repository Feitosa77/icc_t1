#ifndef LINEAR_H
#define LINEAR_H

#include <stdlib.h> /* malloc, free, atof */
#include <stdio.h>  /* printf */
#include <string.h> /* strtok */

#define B_SIZE 1024

/* Vector */

typedef double* Vector; /* v[k], k \in [0..order-1] */

Vector vector_create(int order); 

Vector vector_clone(Vector x, int order); /* Retorna uma copia de x */

void vector_destroy(Vector x);

void vector_print(Vector x, int order);

void vector_printf(Vector x, int order);

void vector_sub(Vector z, Vector x, Vector y,  int order); /* z = x-y */

/* Matrix */

typedef double** Matrix; /* v[l][k], l \in [0..i-1], k \in [0..j-1] */

Matrix matrix_create(int i, int j);

Matrix matrix_clone(Matrix A, int i, int j); /* Retorna uma copia de A */

void matrix_destroy(Matrix A, int i);

void matrix_print(Matrix A, int i, int j);

void matrix_vector_mul(Matrix A, Vector x, Vector b, int order); /* b = Ax */

    /* Augmented */

typedef Matrix Augmented;

/* Le da stdin um inteiro n
    seguido de n streams de n+1 inteiros
    Quebra esses valoers em uma matriz A_nxn e um vetor b
*/
void augmented_read(Matrix A, Vector b, int order);

#endif

