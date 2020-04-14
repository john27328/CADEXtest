#include <iostream>
#include "point.h"
#include "curve.h"
#include <vector>
#include <ctime>
#include <algorithm>
#include <memory>
#include <random>

using curvePtr = shared_ptr<Curve>;
using VecCurve = vector<curvePtr>;
using CirclePtr = shared_ptr<Circle>;
using VecCircle = vector<CirclePtr>;

void createRandomVector(int const nVec, VecCurve &vec);

void sampleCircle(const VecCurve & vec, VecCircle & new_vec);

void printCurves(const VecCurve & vec);

void sortCurve(VecCircle &nvec);

double summCurve(const VecCircle &nvec);

int main()
{
    VecCurve vec;
    createRandomVector(20, vec); // 2. Заполняю вектор

    printCurves(vec); // 3. Вывожу точки и координаты

    VecCircle nvec;
    sampleCircle(vec, nvec); // 4. Заполняю второй контейнер кругами

    sortCurve(nvec); //5. Сортирую

    cout << "rSumm = " << summCurve(nvec) << endl; //6. Считаю сумму

    return 0;
}

void createRandomVector(int const nVec, VecCurve &vec)
{
    double const rMax = 20;
    double const stepMax = 10;

    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> disR(0, rMax);
    std::uniform_real_distribution<> disStep(0, stepMax);

    //double const coord_max = 30;

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
                                      disR(gen)));
            iC++;
            break;
        case 1:
            vec.push_back(make_shared<Ellipse>(Point(x,y,z),
                                       disR(gen),
                                       disR(gen)));
            iE++;
            break;
        case 2:
            vec.push_back(make_shared<Helix>(Point(x,y,z),
                                     disR(gen),
                                     disStep(gen)));
            iH++;
            break;
        default:
            break;

        }
    }
}

void printCurves(const VecCurve & vec){
    std::cout.setf(std::ios::fixed);
    std::cout.precision(4);
    for(const auto &i: vec){
        std::cout << i->name()
            << "\t\tpoint" << i->getPoint(PI/4.)
           << "\t\tdif" << i->getDif(PI/4.) << endl;
    }
}

void sortCurve(VecCircle &nvec){
    sort(nvec.begin(), nvec.end(),
         [](const CirclePtr a, const CirclePtr b) -> bool
    {
        return a->getR() < b->getR();
    });
}

void sampleCircle(const VecCurve &vec, VecCircle &new_vec)
{
    for(auto i: vec){
        auto crc = dynamic_pointer_cast<Circle>(i);
        if (crc){
            new_vec.push_back(crc);
            //std::cout << "sample " << typeid(Circle).name() << " " << typeid(new_vec).name() << endl;
        }
    }
}

double summCurve(const VecCircle &nvec){
    double rSumm = 0;
    for(const auto &i: nvec){
        double r = i->getR();
        //cout << "r = "<< r <<endl;
        rSumm+=r;
    }
    return rSumm;
}
