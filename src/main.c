#include <stdio.h>
#include "fitting.h"
#include "utils.h"

int main()
{
    unsigned int order, length;
    Time time;

    scanf("%d", &order);
    scanf("%d", &length);

    order++;

    Point **points = create_points(length);

    Vector coefficients = least_squares_alt(points, order, length, &time);

    vector_print(coefficients, order);
    printf("%lf\n%lf\n", time.generating, time.solving);

    vector_destroy(coefficients);
    free_points(points, length);

    return EXIT_SUCCESS;
}
