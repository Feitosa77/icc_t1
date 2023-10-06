#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>

#include "ir.h"

struct point
{
    IR x;
    IR y;
};

typedef struct point Point;

/*
 * @brief: Creates an array of points with the given coordinates.
 * @param x: The x coordinate of the point.
 * @param y: The y coordinate of the point.
 * @return: A pointer to the created point.
 */
Point **create_points(unsigned int length);

/*
 * @brief: Prints the given points.
 * @param points: The points to be printed.
 * @param length: The length of the points array.
 */
void print_points(Point **points, unsigned int length);

/*
 * @brief: Frees the memory allocated for the given points.
 * @param points: The points to be freed.
 * @param length: The length of the points array.
 */
void free_points(Point **points, unsigned int length);

#endif
