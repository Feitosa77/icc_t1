#include "fitting.h"

/* Seguindo a notacao do livro
    order = grau do polinomio
    m = quantidade de pontos
*/

Vector least_squares(Point **points, int order, int n_points) {
    int i, j, k;

    Matrix A = matrix_create(order, order);
    Vector x = vector_create(order);
    Vector b = vector_create(order);

    for (i = 0; i < order; ++i) {
        for (j = 0; j < order; ++j) { /* A[i][] */
            A[i][j] = 0.0;

            for (k = 0; k < n_points; ++k) /* A[][j] */
                A[i][j] += pow(points[k]->x, i+j);
        }

        b[i] = 0.0;
        for (k = 0; k < n_points; ++k) /* b[i] */
            b[i] += pow(points[k]->x, i) * points[k]->y; 
    }

    gaussian_elimination(A, x, b, order);

    vector_destroy(b);
    matrix_destroy(A, order);

    return x;
}
