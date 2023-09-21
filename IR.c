#include "IR.h"

void IR_init(IR *x, double val) {
    x->a = nextafterf(val, DBL_MIN);
    x->b = nextafterf(val, DBL_MAX);
}

void IR_sum(IR *z, IR x, IR y) { /* Z := X + Y */
    z->a += x.a + y.a;
    z->b += x.b + y.b;
}

void IR_sub(IR *z, IR x, IR y) { /* Z := X - Y */
    z->a = x.a - y.b;
    z->b = x.b - y.a;
}

int cpmdouble(const void *d1, const void *d2) {
    return (*(float*) d1 > *(float*) d2 ? 1 : -1); /*!!!*/ 
}

void IR_mul(IR *z, IR x, IR y) { /* Z := X * Y */
    float aux[4];

    aux[0] = x.a * y.a;
    aux[1] = x.a * y.b;
    aux[2] = x.b * y.a;
    aux[3] = x.b * y.b;

    qsort(&aux, 4, sizeof (float), cpmdouble); /* Ineficiente */

    z->a = aux[0]; 
    z->b = aux[3];
}

void IR_div(IR *z, IR x, IR y) { /* Z := X / Y */
    if (y.a > DBL_EPSILON || y.b > DBL_EPSILON) {
        y.a = 1/y.a;
        y.b = 1/y.b;
        IR_mul(z, x, y);
    }
    else {
        z->a = -INFINITY; 
        z->b = INFINITY;
    }
}

void IR_print(IR x) {
    float er = x.b-x.a;

    /* le os bytes na memoria como long 64bits */
    long ulp = *(long*)&x.b - *(long*)&x.a;

    printf("[%1.8e,%1.8e]\n", x.a, x.b);
    printf("EA: %1.8e; ER: %1.8e; ULPS: %lu\n", er, er/x.a, ulp);
}

