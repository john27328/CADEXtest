#include "curve.h"

Curve::Curve()
{

}

Circle::Circle() //
{
    this->c = Point(1,2,0);
    this->r = 3;
}

Circle::Circle(Point c, double r)
{
    this->c = c;
    this->r = r;
}

Point Circle::getPoint(double t)
{
    double x = c.x() + r * cos(t);
    double y = c.y() + r * sin(t);
    double z = c.z();
    return Point(x, y, z);
}

Ellipse::Ellipse()
{
    this->c = Point(1,2,0);
    this->rx = 4;
    this->ry = 5;
}

Ellipse::Ellipse(Point c, double rx, double ry)
{
    this->c = c;
    this->rx = rx;
    this->ry = ry;
}

Point Ellipse::getPoint(double t)
{
    double x = c.x() + rx * cos(t);
    double y = c.y() + ry * sin(t);
    double z = c.z();
    return Point(x, y, z);
}

Helix::Helix()
{
    this->c = Point(1,2,0);
    this->r = 6;
    this->s = 5;
}

Helix::Helix(Point c, double r, double step)
{
    this->c = c;
    this->r = r;
    this->s = step;
}

Point Helix::getPoint(double t)
{
    const double PI  =3.141592653589793238463;
    double x = c.x() + r * cos(t);
    double y = c.y() + r * sin(t);
    double z = c.z() + r * t / 2 / PI;
    return Point(x, y, z);
}
