#ifndef POINT_H
#define POINT_H

#include <stdlib.h>
#include <math.h>

typedef struct Point Point;

Point* PointDefaultConstructor(void);
Point* PointConstructor(const double x, const double y);

void PointDestructor(Point** point);

double distanceTo(Point* point, Point* other);


#endif
