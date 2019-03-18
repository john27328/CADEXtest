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

void Point::get(double &x, double &y, double &z)
{
    x = point[0];
    y = point[1];
    z = point[2];
}

double Point::x()
{
    return point[0];
}

double Point::y()
{
    return point[1];
}

double Point::z()
{
    return point[2];
}

std::ostream& operator<< (std::ostream &out, const Point &point)
{
    out << "(" << point.point[0] << ", " << point.point[1]  << ", " << point.point[2]  << ")";

    return out;
}
