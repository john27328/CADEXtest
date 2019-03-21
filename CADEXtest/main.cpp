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
    auto nvec = Tools::sample<Circle >(vec);
    return 0;
}
