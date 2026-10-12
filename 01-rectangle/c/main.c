#include <stdio.h>
#include <stdbool.h>
#include "rectangle.h"

static void check(bool status, const char *message) {
    if (!status) {
        printf("[FAIL]: %s\n", message);
        exit(1);
    }
}


int main(void) {
    Rectangle *rect = RectangleConstructor(10, 20);
    check(rect != NULL, "RectangleConstructor return NULL, check width and height");
    check(area(rect) == 200, "area should return 200");
    check(perimeter(rect) == 60, "perimeter should return 60");

    Rectangle *rectangleSquare = RectangleConstructor(5, 5);
    check(rectangleSquare != NULL, "RectangleConstructor return NULL, check width and height");
    check(area(rectangleSquare) == 25, "area should return 25");
    check(perimeter(rectangleSquare) == 20, "perimeter should return 20");

    RectangleDestructor(&rectangleSquare);
    RectangleDestructor(&rect);

    check(rectangleSquare == NULL, "RectangleDestructor should set pointer to NULL");
    check(rect == NULL, "RectangleDestructor should set pointer to NULL");

    printf("Everything passed!");

    return 0;
}
