#include "curve.h"

Curve::Curve()
{

}

Circle::Circle()
{
    this->c = Point(0,1,2);
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
