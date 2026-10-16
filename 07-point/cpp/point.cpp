#include "point.hpp"
#include <cmath>

Point::Point() : x(0), y(0) {}

Point::Point(double x, double y) : x(x), y(y) {}

double Point::distanceTo(const Point& other) const {
    double dx = this->x - other.x;
    double dy = this->y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}
