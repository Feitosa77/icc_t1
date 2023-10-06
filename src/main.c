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

    IR r, aux;
    
    for (int i = 0; i < length; ++i) {
        r.a = 0.0; r.b = 0.0;

        for (int j = 0; j < order; ++j) { // Calculo y_i
            ir_ipow(&aux, points[i]->x, j);
            ir_mul(&aux, coefficients[j], aux);
            ir_sum(&r, r, aux);
        }

        ir_sub(&r, points[i]->y, r);

        vector_print(&r, 1);
    }


    free_points(points, length);
    vector_destroy(coefficients);

    return EXIT_SUCCESS;
}
