#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
public:
    explicit Point(double x = 0, double y = 0, double z = 0);
    void set(double x = 0, double y = 0, double z = 0 );
    void get(double &x, double &y, double &z);
    double x();
    double y();
    double z();
    friend std::ostream& operator<< (std::ostream &out, const Point &point);
private:
    double point[3];
};

#endif // POINT_H
