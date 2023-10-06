#include "point.h"

Point **create_points(unsigned int length)
{
    Point **points = (Point **)malloc(length * sizeof(Point *));

    if (points == NULL)
        exit(EXIT_FAILURE);

    for (unsigned int i = 0; i < length; i++)
    {
        double d0, d1;

        scanf("%lf %lf", &d0, &d1);

        points[i] = (Point *)malloc(sizeof(Point));

        if (points[i] == NULL)
            exit(EXIT_FAILURE);

        ir_init(&points[i]->x, d0);
        ir_init(&points[i]->y, d1);
    }

    return points;
}

void print_points(Point **points, unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
    {
        ir_print(points[i]->x);
        ir_print(points[i]->y);
        putchar('\n');
    }
    putchar('\n');
}

void free_points(Point **points, unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
        free(points[i]);
    free(points);
}
