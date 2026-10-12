#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(double width, double height) : width(width), height(height) {
    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("width and height must be positive");
    }
}

double Rectangle::area() const {
    return this->width * this->height;
}

double Rectangle::perimeter() const {
    return 2 * (this->width + this->height);
}
