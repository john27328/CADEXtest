#include <iostream>
#include "point.h"
#include "curve.h"
#include "tools.h"


using namespace std;

template<typename T, typename T1>
T test(T vec)
{
    cout << "test " << typeid(T1).name() << endl;
}

template<typename T, typename T1>
T1* sample(T1* vec)
{
    auto new_vec = new T1;
    for(auto i: *vec){
        if (typeid (*i) == typeid (T)){
             new_vec->push_back(i);
            cout << "sample " << typeid(T1).name() <<" " << typeid(new_vec).name()  << endl;
        }
    }
    return  new_vec;
}

int main()
{
    auto *crc = new Helix;
    double t=PI * 2;
    cout << "t = "  << t<< " point" << crc->getPoint(t) << " diff" << crc->getDif(t) << " test" << crc->dif(t, 1e-6) << endl;
    auto vec = Tools::createRandomVector(10);
    for(auto i: *vec){
        cout <<typeid (*i).name()<<" "<<(typeid (*i) == typeid (Circle))<<endl;
    }
    cout << typeid (vec).name() << " " << typeid(vector<Curve *>*).name()<<endl;
    auto nvec = sample<Circle, vector<Curve *> >(vec);
    test<vector<Curve *>*, Circle>(vec);
    return 0;
}
