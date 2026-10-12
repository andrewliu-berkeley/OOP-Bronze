#ifndef CIRCLE_H
#define CIRCLE_H

#include "constant.h"

typedef struct Circle Circle;
Circle *CircleConstructor(double radius);

double area(const Circle *cycle);
double circumference(const Circle *circle);

void CircleDestructor(Circle **circle);

#endif
