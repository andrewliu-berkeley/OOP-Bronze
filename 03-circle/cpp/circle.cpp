#include "circle.hpp"
#include "constant.hpp"
#include <stdexcept>

Circle::Circle(double radius) : _radius(radius) {
    if (radius < 0) {
        throw std::invalid_argument("radius must be non-negative");
    }
}
double Circle::area() const {
    return M_PI * _radius * _radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * _radius;
}
