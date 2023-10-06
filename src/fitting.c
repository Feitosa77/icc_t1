#include "fitting.h"

/* Seguindo a notacao do livro
    order = grau do polinomio
    m = quantidade de pontos
*/

Vector least_squares(Point **points, int order, int n_points)
{
    /* Geracao */
    int i, j, k;
    IR aux;

    Matrix A = matrix_create(order, order);
    Vector x = vector_create(order);
    Vector b = vector_create(order);

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

    /* Solucao */
    gaussian_elimination(A, x, b, order);

    vector_destroy(b);
    matrix_destroy(A, order);

    return x;
}


Vector least_squares_alt(Point **points, int order, int n_points, Time *time)
{
    char MARKER_NAME_1[] = "MarkerGen";
    char MARKER_NAME_2[] = "MarkerSol";


    LIKWID_MARKER_INIT;
    /* Geracao */
    LIKWID_MARKER_START(MARKER_NAME_1);

    time->generating = timestamp();

    int i, j, k;
    IR aux;

    Matrix A = matrix_create(order, order);
    Vector x = vector_create(order);
    Vector b = vector_create(order);

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

    time->generating = timestamp() - time->generating;
    LIKWID_MARKER_STOP(MARKER_NAME_1);

    /* Solucao */
    LIKWID_MARKER_START(MARKER_NAME_2);
        time->solving = timestamp();
            gaussian_elimination(A, x, b, order);
        time->solving = timestamp() - time->solving;
    LIKWID_MARKER_STOP(MARKER_NAME_2);

    vector_destroy(b);
    matrix_destroy(A, order);

    LIKWID_MARKER_CLOSE;

    return x;
}
