#ifndef CURVE_H
#define CURVE_H

#include "point.h"
#include "cmath"

class Curve
{
public:
    explicit Curve();
    virtual Point getPoint(double t) {}
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

class Ellipse:  Curve
{
public:
    explicit Ellipse();
    explicit Ellipse(Point c, double rx, double ry);
    Point getPoint(double t);
private:
    Point c;
    double rx;
    double ry;
};

#endif // CURVE_H
