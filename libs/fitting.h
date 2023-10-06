#ifndef FITTING_H
#define FITTING_H

#include <math.h>
#include "point.h"
#include "linear.h"
#include "elimination.h"

/*
 * @brief: Calculates the coefficients of the least squares polynomial.
 * @param points: The points to fit.
 * @param A: The matrix of the system.
 * @param x: The vector to store the solution.
 * @param b: The vector of the system.
 * @param order: The order of the polynomial.
 * @param n_points: The number of points.
 */
void least_squares(Point **points, Matrix A, Vector x, Vector b, int order, int n_points);

#endif
