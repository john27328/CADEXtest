#include <iostream>
#include "point.h"
#include "curve.h"
#include <vector>
#include <ctime>
#include <algorithm>
#include <memory>


using namespace std;
using curvePtr = shared_ptr<Curve>;
using VecCurve = vector<curvePtr>;
using CirclePtr = shared_ptr<Circle>;
using VecCircle = vector<CirclePtr>;

void createRandomVector(int const nVec, VecCurve &vec);

void sampleCircle(VecCurve & vec, VecCircle & new_vec);

int main()
{
    VecCurve vec;
    createRandomVector(20, vec); // 2. Заполняю вектор

    std::cout.setf(std::ios::fixed);
    std::cout.precision(4);
    for(auto i: vec){
        cout <<i->name()
            <<"\t\tpoint"<<i->getPoint(PI/4.)
           <<"\t\tdif"<<i->getDif(PI/4.)<<endl; // 3. Вывожу точки и координаты
    }

//    cout << "vec " << typeid(vec).name() <<" " << typeid(VecCurve).name()  << endl;
    VecCircle nvec;
    sampleCircle(vec, nvec); // 4. Заполняю второй контейнер кругами
    sort(nvec.begin(),nvec.end(), //5. Сортирую
         [](const CirclePtr a, const CirclePtr b) -> bool
    {
        return a->getR() < b->getR();
    });

    double rSumm = 0; //6. Считаю сумму
    for(auto i: nvec){
        double r = i->getR();
        //cout <<"r = "<< r <<endl;
        rSumm+=r;
    }
    cout << "rSumm = " <<rSumm<<endl;

    return 0;
}

void createRandomVector(int const nVec, VecCurve &vec)
{
    srand( time(0) );
    double const r_max = 20;
    //double const coord_max = 30;
    double const step_max = 10;
    int iC = 0;
    int iE = 0;
    int iH = 0;
    while(iC*iE*iH == 0 || (iC + iE + iH) < nVec) {
        int curve = rand()%3;
//        double x = (double)rand()/RAND_MAX * coord_max;
//        double y = (double)rand()/RAND_MAX * coord_max;
        double x =0;
        double y = 0;
        double z = 0;
        switch (curve) {
        case 0:
            vec.push_back(make_shared<Circle>(Point(x,y,z),
                                      (double)rand()/RAND_MAX * r_max));
            iC++;
            break;
        case 1:
            vec.push_back(make_shared<Ellipse>(Point(x,y,z),
                                       (double)rand()/RAND_MAX * r_max,
                                       (double)rand()/RAND_MAX * r_max));
            iE++;
            break;
        case 2:
            vec.push_back(make_shared<Helix>(Point(x,y,z),
                                     (double)rand()/RAND_MAX * r_max,
                                     (double)rand()/RAND_MAX * step_max));
            iH++;
            break;
        default:
            break;

        }
    }
}

void sampleCircle(VecCurve &vec, VecCircle &new_vec)
{
    for(auto i: vec){
        if (typeid (*i) == typeid (Circle)){
            new_vec.push_back(static_pointer_cast<Circle>(i));
            //cout << "sample " << typeid(Circle).name() <<" " << typeid(new_vec).name()  << endl;
        }
    }
}
