#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle {
public:
    explicit Circle(double radius);
    double area() const;
    double perimeter() const;
private:
    double _radius;
};

#endif
