#include "curve.h"

Curve::Curve()
{

}

Point Curve::dif(double t, double dt)
{
    double dx = (this->getPoint(t + dt).x() - this->getPoint(t).x()) / dt;
    double dy = (this->getPoint(t + dt).y() - this->getPoint(t).y()) / dt;
    double dz = (this->getPoint(t + dt).z() - this->getPoint(t).z()) / dt;
    return Point(dx,dy,dz);
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

Point Circle::getDif(double t)
{
    double dx = -r * sin(t);
    double dy = r * cos(t);
    double dz = 0;
    return Point(dx,dy,dz);
}

void Circle::get(double t, Point point, Point dif)
{
    point = this->getPoint(t);
    dif = this->getDif(t);
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

Point Ellipse::getDif(double t)
{
    double dx = -rx * sin(t);
    double dy = ry * cos(t);
    double dz = 0;
    return Point(dx,dy,dz);
}

void Ellipse::get(double t, Point point, Point dif)
{
    point = this->getPoint(t);
    dif = this->getDif(t);
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

Point Helix::getDif(double t)
{
    const double PI  =3.141592653589793238463;
    double dx = -r * sin(t);
    double dy = r * cos(t);
    double dz = r / 2 / PI;
    return Point(dx,dy,dz);
}

void Helix::get(double t, Point point, Point dif)
{
    point = this->getPoint(t);
    dif = this->getDif(t);
}

