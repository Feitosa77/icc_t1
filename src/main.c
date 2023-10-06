#include <stdio.h>
#include <likwid.h>

#include "fitting.h"
#include "utils.h"

int main()
{
    unsigned int order, length;
    double generating_time, solving_time;

    Matrix A;
    Vector x, b;
    Point **points;

    scanf("%d", &order);
    scanf("%d", &length);

    points = create_points(length);

    A = matrix_create(order, order);
    x = vector_create(order);
    b = vector_create(order);

    LIKWID_MARKER_INIT;

    char MARKER_NAME_1[] = "MarkerGen";

    LIKWID_MARKER_START(MARKER_NAME_1);
    generating_time = timestamp();
    least_squares(points, A, x, b, order, length);
    generating_time = timestamp() - generating_time;
    LIKWID_MARKER_STOP(MARKER_NAME_1);

    char MARKER_NAME_2[] = "MarkerSol";

    LIKWID_MARKER_START(MARKER_NAME_2);
    solving_time = timestamp();
    gaussian_elimination(A, x, b, order);
    back_substitution(A, x, b, order);
    solving_time = timestamp() - solving_time;
    LIKWID_MARKER_STOP(MARKER_NAME_2);

    LIKWID_MARKER_CLOSE;

    vector_print(x, order);
    printf("%lf\n%lf\n", generating_time, solving_time);

    free_points(points, length);
    matrix_destroy(A, order);
    vector_destroy(x);
    vector_destroy(b);

    return EXIT_SUCCESS;
}
