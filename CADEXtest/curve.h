#ifndef CURVE_H
#define CURVE_H

#include "point.h"
#include "cmath"

#define PI 3.141592653589793238463

class Curve
{
public:
    explicit Curve();
    virtual ~Curve() {}

    virtual Point getPoint(double t ) const = 0;
    virtual Point getDif(double t) const = 0;
    virtual void get(double t, Point point, Point dif) const = 0;
    virtual string name() const = 0;
    //Point dif(double t, double dt);
};

class Circle:  public Curve
{
public:
    explicit Circle();
    explicit Circle(Point c, double r);
    ~Circle(){
        //cout<<" ~Circle()"<<endl;
    }
    Point getPoint(double t) const override;
    Point getDif(double t) const override;
    void get(double t, Point point, Point dif) const override;
    string name() const override;

    double getR() const;

private:
    Point c;
    double r;
};

class Ellipse: public Curve
{
public:
    explicit Ellipse();
    explicit Ellipse(Point c, double rx, double ry);
    ~Ellipse(){
        //cout<<" ~Ellipse()"<<endl;
    }
    Point getPoint(double t) const override;
    Point getDif(double t) const override;
    void get(double t, Point point, Point dif) const override;
    string name() const override;

    double getRx() const;
    double getRy() const;

private:
    Point c;
    double rx;
    double ry;
};

class Helix: public Curve
{
public:
    explicit Helix();
    explicit Helix(Point c, double r, double step);
    ~Helix(){
        //cout<<" ~Helix()"<<endl;
    }
    Point getPoint(double t) const override;
    Point getDif(double t) const override;
    void get(double t, Point point, Point dif) const override;
    string name() const override;

    double getR() const;
    double getS() const;

private:
    Point c;
    double r;
    double s;
};

#endif // CURVE_H
