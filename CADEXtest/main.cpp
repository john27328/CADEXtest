#include <iostream>
#include "point.h"
#include "curve.h"
#include "tools.h"


using namespace std;

int main()
{
    auto *crc = new Helix;
    double t=PI * 2;
    cout << "t = "  << t<< " point" << crc->getPoint(t) << " diff" << crc->getDif(t) << " test" << crc->dif(t, 1e-6) << endl;
    auto vec = Tools::createRandomVector(10);
    for(auto i: *vec){
        cout <<typeid (*i).name()<<" "<<(typeid (*i) == typeid (Circle))<<endl;
    }
    vector<Curve *> * nvec = Tools::sample<Circle>(vec);
    return 0;
}
