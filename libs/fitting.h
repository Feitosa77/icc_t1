#ifndef FITTING_H
#define FITTING_H

#include <math.h>
#include <likwid.h>
#include "point.h"
#include "linear.h"
#include "elimination.h"
#include "utils.h"

/*
 * @brief: Calculates the coefficients of the least squares polynomial.
 * @param points: The points to fit.
 * @param order: The order of the polynomial.
 * @param n_points: The number of points.
 */
Vector least_squares(Point **points, int order, int n_points);

Vector least_squares_alt(Point **points, int order, int n_points, Time *time);

#endif
