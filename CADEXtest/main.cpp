#include <iostream>
#include "point.h"
#include "curve.h"
#include "tools.h"
#include <algorithm>


using namespace std;

vector <Curve *>* createRandomVector(int const n);

template<typename T, typename T1>
vector<T *> *sample(T1 *vec);


int main()
{
    //не забыть стереть
    auto *crc = new Helix;
    double t=PI * 2;
    cout << "t = "  << t<< " point" << crc->getPoint(t) << " diff" << crc->getDif(t) << " test" << crc->dif(t, 1e-6) << endl;

    auto vec = createRandomVector(20);

    for(auto i: *vec){
        cout <<typeid (*i).name()<<" point"<<i->getPoint(PI/4.) <<" dif"<<i->getDif(PI/4.)<<endl;
    }

    auto nvec = sample<Circle >(vec);

//    for(auto i: *nvec){
//        cout <<"r = "<< i->getR() <<endl;
//    }

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

vector <Curve *>* createRandomVector(int const n)
{
    auto vec = new vector <Curve *>;
    srand( time(0) );
    double const r_max = 20;
    //double const coord_max = 30;
    double const step_max = 10;

    for (int i = 0; i < n; i++) {
        int curve = rand()%3;
//        double x = (double)rand()/RAND_MAX * coord_max;
//        double y = (double)rand()/RAND_MAX * coord_max;
        double x =0;
        double y = 0;
        double z = 0;
        switch (curve) {
        case 0:
            vec->push_back(new Circle(Point(x,y,z),
                                      (double)rand()/RAND_MAX * r_max));
            break;
        case 1:
            vec->push_back(new Ellipse(Point(x,y,z),
                                       (double)rand()/RAND_MAX * r_max,
                                       (double)rand()/RAND_MAX * r_max));
            break;
        case 2:
            vec->push_back(new Helix(Point(x,y,z),
                                     (double)rand()/RAND_MAX * r_max,
                                     (double)rand()/RAND_MAX * step_max));
            break;
        default:
            break;

        }
    }
    return vec;
}

template<typename T, typename T1>
vector<T *> *sample(T1 *vec)
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
