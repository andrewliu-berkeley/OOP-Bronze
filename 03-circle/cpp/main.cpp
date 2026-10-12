#include <cstdlib>
#include <iostream>
#include <cmath>
#include <string>
#include "circle.hpp"
#include "constant.hpp"


static void check (bool status, const std::string& message) {
    if (!status) {
        std::cerr << "Error: " << message << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main(void) {
    Circle *circle = new Circle(2.0);
    check(std::abs(circle->area()) - 12.56636 < EPSILON, "area computed incorrectly");
    check(std::abs(circle->perimeter()) - 31.41592 < EPSILON, "perimeter computed incorrectly");

    delete circle;
    circle = nullptr;
    check(circle == nullptr, "circle should be null after deletion");

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
