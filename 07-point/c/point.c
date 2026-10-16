#include "point.h"

struct Point {
    double x;
    double y;
};

Point* PointDefaultConstructor(void) {
    Point* p = malloc(sizeof(Point));
    p->x = 0;
    p->y = 0;
    return p;
}

Point* PointConstructor(const double x, const double y) {
    Point* p = malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    return p;
}

void PointDestructor(Point** point) {
    free(*point);
    *point = NULL;
}

double distanceTo(Point *point, Point *other){
    double dx = point->x - other->x;
    double dy = point->y - other->y;
    return sqrt(dx*dx + dy*dy);
}
