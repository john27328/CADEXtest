#ifndef CURVE_H
#define CURVE_H

#include "point.h"
#include "cmath"

class Curve
{
public:
    explicit Curve();
    virtual Point getPoint(double t) const = 0;
    virtual ~Curve() {}
};

class Circle:  Curve
{
public:
    explicit Circle();
    explicit Circle(Point c, double r);
    Point getPoint(double t);
private:
    Point c;
    double r;
};

#endif // CURVE_H
