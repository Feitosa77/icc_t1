#include "ir.h"

#define m(val) nextafter(val, DBL_MIN)
#define M(val) nextafter(val, DBL_MAX)

void ir_init(IR *x, double val) {
    x->a = nextafter(val, DBL_MIN);
    x->b = nextafter(val, DBL_MAX);
}

void ir_sum(IR *z, IR x, IR y) { /* Z := X + Y */
    z->a = m(x.a + y.a);
    z->b = M(x.b + y.b);
}

void ir_sub(IR *z, IR x, IR y) { /* Z := X - Y */
    z->a = m(x.a - y.b);
    z->b = M(x.b - y.a);
}

int cpmdouble(const void *d1, const void *d2) {
    return (*(float*) d1 > *(float*) d2 ? 1 : -1); /*!!!*/ 
}

void ir_mul(IR *z, IR x, IR y) { /* Z := X * Y */
    float aux[4];

    aux[0] = x.a * y.a;
    aux[1] = x.a * y.b;
    aux[2] = x.b * y.a;
    aux[3] = x.b * y.b;

    qsort(&aux, 4, sizeof (float), cpmdouble); /* Ineficiente */

    z->a = m(aux[0]); 
    z->b = M(aux[3]);
}

void ir_div(IR *z, IR x, IR y) { /* Z := X / Y */
    if (y.a > DBL_EPSILON || y.b > DBL_EPSILON) {
        y.a = m(1/y.a);
        y.b = M(1/y.b);
        ir_mul(z, x, y);
    }
    else {
        z->a = -INFINITY; 
        z->b = INFINITY;
    }
}

void ir_ipow(IR *z, IR x, int value) { /* Temporario */
    if (!value) {
            z->a = 1.0;
            z->b = 1.0;
    } 
    else  {
        double a = m(pow(x.a, value));
        double b = m(pow(x.b, value));

        if ((value & 1) == 1) { /* Impar */
            z->a = a;
            z->b = b;
        }
        else { /* Par */
            if (x.a >= 0) {
                z->a = a;
                z->b = b;
            }
            else if (x.b < 0) {
                z->a = b;
                z->b = a;
            }
            if (x.a < 0 && 0 <= x.b) {
                z->a = 0;
                z->b = (a > b ? a : b);
            }
        }
    }
}

void ir_print(IR x) {
    float er = x.b-x.a;

    /* le os bytes na memoria como long 64bits */
    long ulp = *(long*)&x.b - *(long*)&x.a;

    printf("[%1.8e,%1.8e]\n", x.a, x.b);
    printf("EA: %1.8e; ER: %1.8e; ULPS: %lu\n", er, er/x.a, ulp);
}

