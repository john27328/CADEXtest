#ifndef TOOLS_H
#define TOOLS_H
#include "point.h"
#include "curve.h"
#include <vector>
#include <ctime>


class Tools
{
public:
    Tools();
    static std::vector<Curve *> *createRandomVector(int n);
};

#endif // TOOLS_H
