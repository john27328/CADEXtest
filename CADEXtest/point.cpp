#include "point.h"

Point::Point(double x, double y, double z)
{
    point[0] = x;
    point[1] = y;
    point[2] = z;
}

void Point::set(double x, double y, double z)
{
    point[0] = x;
    point[1] = y;
    point[2] = z;
}

void Point::get(double &x, double &y, double &z) const
{
    x = point[0];
    y = point[1];
    z = point[2];
}

double Point::x() const
{
    return point[0];
}

double Point::y() const
{
    return point[1];
}

double Point::z() const
{
    return point[2];
}

ostream& operator<< (ostream &out, const Point &point)
{
    out << "(" << point.point[0] << ", " << point.point[1]  << ", " << point.point[2]  << ")";

    return out;
}
