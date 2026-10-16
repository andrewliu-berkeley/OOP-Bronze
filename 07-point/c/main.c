#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "point.h"


static void check (bool status, const char* message) {
    if (!status) {
        fprintf(stderr, "Error: %s\n", message);
        exit(EXIT_FAILURE);
    }
}

int main(void){
    Point *point = PointConstructor(3, 4);
    check(point != NULL, "PointConstructor return NULL");

    Point *point2 = PointDefaultConstructor();
    check(point2 != NULL, "PointDefaultConstructor return NULL");

    check(fabs(distanceTo(point, point2) - 5) < 1e-9, "Distance (0,0)-(3,4) must be 5");
    check(fabs(distanceTo(point2, point) - 5) < 1e-9, "Distance must be symmetric");

    PointDestructor(&point);
    PointDestructor(&point2);

    check(point == NULL, "PointDestructor must set pointer to NULL");
    check(point2 == NULL, "PointDestructor must set pointer to NULL");

    printf("All tests passed.\n");
    return 0;
}
