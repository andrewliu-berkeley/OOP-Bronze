#include <cstdlib>
#include <iostream>
#include <memory>
#include "point.hpp"

const double EPS = 1e-9;

void check (bool status, const std::string& message) {
    if (!status) {
        std::cerr << "Error: " << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    Point point(3.0, 4.0);
    std::unique_ptr<Point> point2 = std::make_unique<Point>();
    check(point2 != nullptr, "Failed to allocate memory for point2");

    check(abs(point.distanceTo(*point2) - 5) < EPS, "Distance (0,0)-(3,4) must be 5");
    check(abs(point2->distanceTo(point) - 5) < EPS, "Distance must be symmetric");

    std::cout << "All tests passed" << std::endl;
    return EXIT_SUCCESS;
}
