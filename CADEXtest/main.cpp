#include <iostream>
#include "point.h"
#include "curve.h"
#include <vector>
#include <ctime>
#include <algorithm>


using namespace std;

vector <Curve *>* createRandomVector(int const n);

template<typename T, typename T1>
vector<T *> *sample(T1 *vec);


int main()
{
    auto vec = createRandomVector(3); // 2. Заполняю вектор

    std::cout.setf(std::ios::fixed);
    std::cout.precision(4);
    for(auto i: *vec){
        cout <<i->name()
            <<"\t\tpoint"<<i->getPoint(PI/4.)
           <<"\t\tdif"<<i->getDif(PI/4.)<<i->dif(PI/4.,1e-6)<<endl; // 3. Вывожу точки и координаты
    }

    auto nvec = sample<Circle >(vec); // 4. Заполняю второй контейнер кругами

    sort(nvec->begin(),nvec->end(), //5. Сортирую
         [](const Circle * a, const Circle * b) -> bool
    {
        return a->getR() < b->getR();
    });

    double rSumm = 0; //6. Считаю сумму
    for(auto i: *nvec){
        double r = i->getR();
        //cout <<"r = "<< r <<endl;
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
    int iC = 0;
    int iE = 0;
    int iH = 0;
    while(iC*iE*iH == 0 || (iC + iE + iH) < n) {
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
            iC++;
            break;
        case 1:
            vec->push_back(new Ellipse(Point(x,y,z),
                                       (double)rand()/RAND_MAX * r_max,
                                       (double)rand()/RAND_MAX * r_max));
            iE++;
            break;
        case 2:
            vec->push_back(new Helix(Point(x,y,z),
                                     (double)rand()/RAND_MAX * r_max,
                                     (double)rand()/RAND_MAX * step_max));
            iH++;
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
