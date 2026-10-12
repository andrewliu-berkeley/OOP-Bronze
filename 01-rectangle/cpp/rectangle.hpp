#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle {
public:
    Rectangle(double width, double height);
    double area() const;
    double perimeter() const;

private:
    const double width;
    const double height;
};

#endif // RECTANGLE_HPP
