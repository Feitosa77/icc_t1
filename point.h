#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>

struct point
{
    double x;
    double y;
};

typedef struct point Point;

Point **create_points(unsigned int length);

void print_points(Point **points, unsigned int length);

void free_points(Point **points, unsigned int length);

void get_interval(Point **points, unsigned int length, double *interval);

#endif
