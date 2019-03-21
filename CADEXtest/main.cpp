#include <iostream>
#include "point.h"
#include "curve.h"
#include "tools.h"
#include <algorithm>


using namespace std;


int main()
{
    auto *crc = new Helix;
    double t=PI * 2;
    cout << "t = "  << t<< " point" << crc->getPoint(t) << " diff" << crc->getDif(t) << " test" << crc->dif(t, 1e-6) << endl;
    auto vec = Tools::createRandomVector(20);

    for(auto i: *vec){
        cout <<typeid (*i).name()<<" point"<<i->getPoint(PI/4.) <<" dif"<<i->getDif(PI/4.)<<endl;
    }

    auto nvec = Tools::sample<Circle >(vec);

    for(auto i: *nvec){
        cout <<"r = "<< i->getR() <<endl;
    }

    sort(nvec->begin(),nvec->end(),
         [](const Circle * a, const Circle * b) -> bool
    {
        return a->getR() < b->getR();
    });

    cout <<"*******************"<<endl;
    double rSumm = 0;
    for(auto i: *nvec){
        double r = i->getR();
        cout <<"r = "<< r <<endl;
        rSumm+=r;
    }
    cout << "rSumm = " <<rSumm;

    return 0;
}
