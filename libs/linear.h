#ifndef LINEAR_H
#define LINEAR_H

#include <stdlib.h> /* malloc, free, atof */
#include <stdio.h>  /* printf */
#include <string.h> /* strtok */

#include "ir.h" /* IR */

#define B_SIZE 1024

/* Vector */

typedef IR* Vector; /* v[k], k \in [0..order-1] */

Vector vector_create(int order); 

void vector_destroy(Vector x);

void vector_print(Vector x, int order);

/* Matrix */

typedef IR** Matrix; /* v[l][k], l \in [0..i-1], k \in [0..j-1] */

Matrix matrix_create(int i, int j);

void matrix_destroy(Matrix A, int i);

void matrix_print(Matrix A, int i, int j);

#endif

