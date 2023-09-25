#include "point.h"

void create_points(point_t ***points, unsigned int size)
{
    *points = (point_t **)malloc(size * sizeof(point_t *));   
    
    for (unsigned int i = 0; i < size; i++)
    {
        (*points)[i] = (point_t *)malloc(sizeof(point_t));
        scanf("%lf %lf", &(*points)[i]->x, &(*points)[i]->y);
    }
}

void print_points(point_t **points, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
        printf("%lf %lf\n", points[i]->x, points[i]->y);
}

void free_points(point_t ***points, unsigned int size)
{
    for (unsigned int i = 0; i < size; i++)
        free((*points)[i]);
    free(*points);
}

void get_interval(point_t **points, unsigned int size, double *interval)
{
    interval[0] = points[0]->x;
    interval[1] = points[0]->x;

    for (int i = 1; i < size; ++i) {
        if (interval[0] > points[i]->x) interval[0] = points[i]->x; /* Min */
        if (interval[1] < points[i]->x) interval[1] = points[i]->x; /* Max */
    }
}

