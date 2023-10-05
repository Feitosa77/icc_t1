#include "elimination.h"

/* Pivoteamento */

void pivot(Matrix A, Vector b, int order, int p) {
    int max = p;
    IR *m_aux = A[p];
    IR v_aux = b[p];

    for (int i = p; i < order; ++i) // Encontra o maior coeficiente da coluna p //
        if (fabs(A[i][p].a) > fabs(A[max][p].a))
            max = i;

    A[p] = A[max];
    A[max] = m_aux;

    b[p] = b[max];
    b[max] = v_aux;
}

/* 1. Forma classica com pivoteamento */

void gaussian_elimination(Matrix A, Vector x, Vector b, int order) {
    int i, j, k;
    IR m, aux;

    for (i = 0; i < order; ++i) {         /* Colunas */
        pivot(A, b, order, i);

        for (k = i+1; k < order; ++k) {   /* Linhas */
            ir_div(&m, A[k][i], A[i][i]);

            for (j = i; j < order; ++j) { /* Deslocamento A[k][j] */
                ir_mul(&aux, A[i][j], m);
                ir_sub(&A[k][j], A[k][j], aux);
            }
            
            ir_mul(&aux, b[i], m);
            ir_sub(&b[k], b[k], aux);
        }
    }

    back_substitution(A, x, b, order);
}

/* 2. Forma classica com pivoteamento, sem o calculo dos multiplicadores */

void gaussian_elimination_var(Matrix A, Vector x, Vector b, int order) {
    int i, j, k;
    IR m, aux0, aux1;


    for (i = 0; i < order; ++i) {       /* Colunas */
        //pivot(A, b, order, i);

        for (k = i+1; k < order; ++k) { /* Linhas */
            m = A[k][i];

            for (j = i; j < order; ++j) { /* Deslocamento A[k][j] */
                ir_mul(&aux0, A[k][j], A[i][i]);
                ir_mul(&aux1, A[i][j], m);

                ir_sub(&A[k][j], aux0, aux1);
            }

            ir_mul(&aux0, b[k], A[i][i]);
            ir_mul(&aux1, b[i], m);

            ir_sub(&b[k], aux0, aux1);

        }
    }

    back_substitution(A, x, b, order);
}


/* A is upper triangular */

void back_substitution(Matrix A, Vector x, Vector b, int order) {
    int i, j;
    IR aux;

    for (i = order-1; i >= 0; --i) {
        x[i] = b[i];

        for (j = i+1; j < order; ++j) {
            ir_mul(&aux, A[i][j], x[j]);
            ir_sub(&x[i], x[i], aux);
        }

        ir_div(&x[i], x[i], A[i][i]);
    }
}
