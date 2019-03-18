#include <iostream>
#include "point.h"
#include "curve.h"

using namespace std;

int main()
{
    Circle *crc = new Circle;
    Point cp = crc->getPoint(-3.14);
    cout << cp << endl;
    Point pnt(1,2,3);
    double x, y, z;
    pnt.set(9,8,7);
    pnt.get(x,y,z);
    y = 5;
    cout << x << y << z <<  "Hello World " << pnt << endl;

    return 0;
}
