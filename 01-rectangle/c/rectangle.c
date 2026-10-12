#include "rectangle.h"

struct Rectangle {
    double width;
    double height;
};

Rectangle *RectangleConstructor(double width, double height) {
    if (width <= 0 || height <= 0){
        return NULL;
    }
    Rectangle *rect = malloc(sizeof(Rectangle));
    rect->width = width;
    rect->height = height;
    return rect;
}

double area(Rectangle *rect) {
    return rect->width * rect->height;
}

double perimeter(Rectangle *rect) {
    return 2 * (rect->width + rect->height);
}

void RectangleDestructor(Rectangle **rect) {
    free(*rect);
    *rect = NULL;
}
