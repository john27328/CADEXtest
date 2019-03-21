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
    static vector<T*>* sample(T1* vec)
    {
        vector<T*> *new_vec = new vector<T*>;
        for(auto i: *vec){
            if (typeid (*i) == typeid (T)){
                new_vec->push_back((T*)i);
                //cout << "sample " << typeid(T).name() <<" " << typeid(new_vec).name()  << endl;
            }
        }
        return  new_vec;
    }
};

#endif // TOOLS_H
