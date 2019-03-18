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
