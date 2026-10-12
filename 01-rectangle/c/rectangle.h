#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdlib.h>

typedef struct Rectangle Rectangle;

Rectangle *RectangleConstructor(double width, double height);

double area(Rectangle *rect);
double perimeter(Rectangle *rect);

void RectangleDestructor(Rectangle **rect);

#endif
