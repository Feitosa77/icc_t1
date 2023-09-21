#ifndef IR_H
#define IR_H

#include <math.h>   /* nextafter e INFINITY */
#include <float.h>  /* DBL_MIN, DBL_MAX e DBL_EPSILON */
#include <stdio.h>  /* printf */
#include <stdlib.h> /* qsort */

/*
 * Intervalo Aberto
 * double a - MAIOR numero de maquina menor ou igual a x
 * double b - MENOR numero de maquina maior ou igual a x
 */

typedef struct IntervalReal IR;

struct IntervalReal { /* [a,b] */
    double a; /* max {a E R | a < x} */
    double b; /* min {b E R | b > x} */
};

void IR_init(IR *x, double val);

void IR_sum(IR *z, IR x, IR y); /* Z := X + Y */

void IR_sub(IR *z, IR x, IR y); /* Z := X - Y */

void IR_mul(IR *z, IR x, IR y); /* Z := X * Y */

void IR_div(IR *z, IR x, IR y); /* Z := X / Y */

void IR_print(IR x);

#endif

