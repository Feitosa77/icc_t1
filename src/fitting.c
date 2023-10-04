#include "fitting.h"

/* Seguindo a notacao do livro
    order = grau do polinomio
    m = quantidade de pontos
*/

void least_squares(Point **points, Matrix A, Vector x, Vector b, int order, int n_points) {
    int i, j, k;

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
}
