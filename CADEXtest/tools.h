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

    template<typename T, typename T1>
    static T1* sample(T1* vec)
    {
        auto new_vec = new T1;
        for(auto i: *vec){
            if (typeid (*i) == typeid (T)){
                 new_vec->push_back(i);
                cout << "sample " << typeid(T).name() <<" " << typeid(*new_vec).name()  << endl;
            }
        }
        return  new_vec;
    }

};

#endif // TOOLS_H
