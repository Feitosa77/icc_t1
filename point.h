#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>

struct point
{
    double x;
    double y;
};

typedef struct point point_t;

void create_points(point_t ***points, unsigned int size);

void print_points(point_t **points, unsigned int size);

void free_points(point_t ***points, unsigned int size);

void get_interval(point_t **points, unsigned int size, double *interval);

#endif

