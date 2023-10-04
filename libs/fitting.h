#ifndef FITTING_H
#define FITTING_H

#include <math.h>
#include "linear.h"
#include "elimination.h"
#include "point.h"

void least_squares(Point **points, Matrix A, Vector x, Vector b, int order, int n_points);

#endif
