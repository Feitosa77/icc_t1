#ifndef FITTING_H
#define FITTING_H

#include <math.h>
#include "linear.h"
#include "elimination.h"
#include "point.h"

Vector least_squares(point_t **points, int order, int n_points);

#endif

