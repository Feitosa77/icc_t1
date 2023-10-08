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

    IR r, aux;
    Vector results = vector_create(length);

    for (int i = 0; i < length; ++i) {
        r.a = 0.0; r.b = 0.0;

        for (int j = 0; j < order; ++j) { // Calculo y_i
            ir_ipow(&aux, points[i]->x, j);
            ir_mul(&aux, coefficients[j], aux);
            ir_sum(&r, r, aux);
        }

        ir_sub(&r, points[i]->y, r);

        results[i] = r;
    }

    vector_print(results, length);
    printf("%.8e\n%.8e\n", time.generating, time.solving);

    free_points(points, length);
    vector_destroy(coefficients);
    vector_destroy(results);

    return EXIT_SUCCESS;
}
