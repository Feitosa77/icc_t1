#include "point.h"

Point **create_points(unsigned int length)
{
    Point **points = (Point **)malloc(length * sizeof(Point *));

    if (points == NULL)
        exit(EXIT_FAILURE);

    for (unsigned int i = 0; i < length; i++)
    {
        points[i] = (Point *)malloc(sizeof(Point));

        if (points[i] == NULL)
            exit(EXIT_FAILURE);

        scanf("%lf %lf", &points[i]->x, &points[i]->y);
    }

    return points;
}

void print_points(Point **points, unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
        printf("%lf %lf", points[i]->x, points[i]->y);
    printf("\n");
}

void free_points(Point **points, unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
        free(points[i]);
    free(points);
}

void get_interval(Point **points, unsigned int length, double *interval)
{
    interval[0] = points[0]->x;
    interval[1] = points[0]->x;

    for (int i = 1; i < length; ++i)
    {
        if (interval[0] > points[i]->x)
            interval[0] = points[i]->x; /* Min */
        if (interval[1] < points[i]->x)
            interval[1] = points[i]->x; /* Max */
    }
}
