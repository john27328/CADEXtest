#include "tools.h"

Tools::Tools()
{

}


vector <Curve *>* Tools::createRandomVector(int const n)
{
    auto vec = new vector <Curve *>;
    srand( time(0) );
    double const r_max = 20;
    double const coord_max = 30;
    double const step_max = 10;
    double x = (double)rand()/RAND_MAX * coord_max;
    double y = (double)rand()/RAND_MAX * coord_max;
    double z = 0;

    for (int i = 0; i < n; i++) {
        int curve = rand()%3;
        double x = (double)rand()/RAND_MAX * coord_max;
        double y = (double)rand()/RAND_MAX * coord_max;
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


