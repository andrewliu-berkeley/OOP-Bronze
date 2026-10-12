#include "circle.h"

#include <stdlib.h>

struct Circle {
    double radius;
};

Circle *CircleConstructor(double radius) {
    if (radius <= 0) {
        return NULL;
    }
    Circle *circle = malloc(sizeof(Circle));
    circle->radius = radius;
    return circle;
}

double area(const Circle *circle) {
    return M_PI * circle->radius * circle->radius;
}

double circumference(const Circle *circle) {
    return 2 * M_PI * circle->radius;
}

void CircleDestructor(Circle **circle) {
    free(*circle);
    *circle = NULL;
}
