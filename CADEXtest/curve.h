#ifndef CURVE_H
#define CURVE_H

#include "point.h"
#include "cmath"

#define PI 3.141592653589793238463

class Curve
{
public:
    explicit Curve();
    virtual Point getPoint(double t ) = 0;
    virtual Point getDif(double t) = 0;
    virtual void get(double t, Point point, Point dif) = 0;
    virtual ~Curve() {}
    Point dif(double t, double dt);
};

class Circle:  public Curve
{
public:
    explicit Circle();
    explicit Circle(Point c, double r);
    Point getPoint(double t);
    Point getDif(double t);
    void get(double t, Point point, Point dif);

    double getR() const;

private:
    Point c;
    double r;
};

class Ellipse: public Curve
{
public:
    explicit Ellipse();
    explicit Ellipse(Point c, double rx, double ry);
    Point getPoint(double t);
    Point getDif(double t);
    void get(double t, Point point, Point dif);
    double getRx() const;

    double getRy() const;

private:
    Point c;
    double rx;
    double ry;
};

class Helix: public Curve
{
public:
    explicit Helix();
    explicit Helix(Point c, double r, double step);
    Point getPoint(double t);
    Point getDif(double t);
    void get(double t, Point point, Point dif);
    double getR() const;

    double getS() const;

private:
    Point c;
    double r;
    double s;
};

#endif // CURVE_H
