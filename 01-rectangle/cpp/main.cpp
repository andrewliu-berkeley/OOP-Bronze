#include "rectangle.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

static void check(bool status, const std::string &message) {
    if (!status) {
        std::cerr << "Error: " << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    Rectangle *rect = new Rectangle(10.0, 5.0);
    check(rect != nullptr, "Failed to allocate memory for Rectangle");
    check(rect->area() == 50.0, "Rectangle area is not 50.0");
    check(rect->perimeter() == 30.0, "Rectangle perimeter is not 30.0");

    Rectangle *rectSquare = new Rectangle(5.0, 5.0);
    check(rectSquare != nullptr, "Failed to allocate memory for Rectangle");
    check(rectSquare->area() == 25.0, "Rectangle area is not 25.0");
    check(rectSquare->perimeter() == 20.0, "Rectangle perimeter is not 20.0");

    delete rect;
    delete rectSquare;
    rect = nullptr;
    rectSquare = nullptr;

    check(rect == nullptr, "Rectangle is not nullptr");
    check(rectSquare == nullptr, "RectangleSquare is not nullptr");

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
