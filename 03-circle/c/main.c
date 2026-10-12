#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "circle.h"

static void check (bool status, const char *message) {
    if (!status) {
        printf("%s\n", message);
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    Circle *circle = CircleConstructor(5.0);
    check(circle != NULL, "CircleConstructor return NULL, please check the radius");
    check(fabs(area(circle) - M_PI * 25.0) < EPSILON, "area calculation is incorrect");
    check(fabs(circumference(circle) - 2 * M_PI * 5.0) < EPSILON, "circumference calculation is incorrect");

    Circle *circle2 = CircleConstructor(5.67);
    check(circle2 != NULL, "CircleConstructor return NULL, please check the radius");
    check(fabs(area(circle2) - M_PI * 5.67 * 5.67) < EPSILON, "area calculation is incorrect");
    check(fabs(circumference(circle2) - 2 * M_PI * 5.67) < EPSILON, "circumference calculation is incorrect");

    CircleDestructor(&circle);
    CircleDestructor(&circle2);

    check(circle == NULL, "CircleDestructor should set the pointer to NULL");
    check(circle2 == NULL, "CircleDestructor should set the pointer to NULL");

    printf("All tests passed.\n");
}
