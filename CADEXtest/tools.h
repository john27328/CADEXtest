#ifndef TOOLS_H
#define TOOLS_H
#include "point.h"
#include "curve.h"
#include <vector>
#include <ctime>
#include <typeinfo>

using namespace std;
class Tools
{
public:
    Tools();
    static vector<Curve *> *createRandomVector(int n);
    template<typename T>
    static vector<Curve *> * sample(vector<Curve *> * vec);
};

#endif // TOOLS_H
