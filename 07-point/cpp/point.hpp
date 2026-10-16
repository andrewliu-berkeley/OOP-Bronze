#ifndef POINT_HPP
#define POINT_HPP

class Point {
public:
    Point();
    Point(double x, double y);
    double distanceTo(const Point& other) const;

private:
    const double x;
    const double y;
};

#endif
