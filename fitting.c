#include "linear.h"

/* Seguindo a notacao do livro
    order = grau do polinomio
    m = quantidade de pontos
*/

Vector least_square(Vector x, Vector y, int order, int n_points) {
    Matrix A = matrix_create(order, order);
    Vector coefi = vector_create(order);
}
