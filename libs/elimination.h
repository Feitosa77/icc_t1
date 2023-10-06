#ifndef ELIMINATION_H
#define ELIMINATION_H

#include <float.h>
#include <math.h>

#include "linear.h"

/*
 * @brief: Performs Gaussian elimination on the given system.
 * @param A: The matrix of the system.
 * @param b: The vector of the system.
 * @param x: The vector to store the solution.
 * @param order: The order of the system.
 */
void gaussian_elimination(Matrix A, Vector b, Vector x, int order);

/*
 * @brief: Performs back substitution on the given system.
 * @param A: The matrix of the system.
 * @param b: The vector of the system.
 * @param x: The vector to store the solution.
 * @param order: The order of the system.
 */
void back_substitution(Matrix A, Vector x, Vector b, int order);

#endif
