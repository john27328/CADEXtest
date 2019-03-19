#include <iostream>
#include "point.h"
#include "curve.h"

using namespace std;

int main()
{
    auto *crc = new Helix;
    double t=3.14/4;
    cout << "t = "  << t<< " point" << crc->getPoint(t) << " diff" << crc->getDif(t) << " test" << crc->dif(t, 1e-6) << endl;
    return 0;
}
