#include "fitting.h"

/* Seguindo a notacao do livro
    order = grau do polinomio
    m = quantidade de pontos
*/

void least_squares(Point **points, Matrix A, Vector x, Vector b, int order, int n_points)
{
    int i, j, k;
    IR aux;

    for (i = 0; i < order; ++i)
    {
        for (j = 0; j < order; ++j)
        { /* A[i][] */
            A[i][j].a = 0.0;
            A[i][j].b = 0.0;

            for (k = 0; k < n_points; ++k)
            {                                       /* A[][j] */
                ir_ipow(&aux, points[k]->x, i + j); /* point[k]->x := double, precisa ser IR */
                ir_sum(&A[i][j], A[i][j], aux);
            }
        }

        b[i].a = 0.0;
        b[i].b = 0.0;
        for (k = 0; k < n_points; ++k)
        { /* b[i] */
            ir_ipow(&aux, points[k]->x, i);
            ir_mul(&aux, aux, points[k]->y); /*point[k]->y := ???, precisa ser int */

            ir_sum(&b[i], b[i], aux);
        }
    }
}
