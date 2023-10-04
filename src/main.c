#include <stdio.h>
#include "point.h"
#include "fitting.h"

int main() {
    unsigned int order, length;

    scanf("%d", &order);
    scanf("%d", &length);

    Point **points = create_points(length);

    Vector coefficients = least_squares(points, order, length);

    vector_print_inf(coefficients, order);
    vector_print_sup(coefficients, order);

    free_points(points, length);
    vector_destroy(coefficients);
    
    return EXIT_SUCCESS;
}
