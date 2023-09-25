#include <stdio.h>
#include "point.h"
#include "fitting.h"

int main() {
    int order, n_points;
    point_t **points;

    scanf("%d", &order); /* Nao 'sei' usar scanf... */
    scanf("%d", &n_points); /* Tmp */

    create_points(&points, n_points);
    
    //printf("%d\n%d\n", order, n_points);
    //print_points(points, n_points);

    Vector coefficients = least_squares(points, order, n_points);

    vector_print(coefficients, order);

    free_points(&points, n_points);
    vector_destroy(coefficients);
    
    return 0;
}

