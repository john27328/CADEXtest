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
    template<class T, class T1>
    static T1 sample(T1 vec);

    template<class T>
    void test();
};

#endif // TOOLS_H
