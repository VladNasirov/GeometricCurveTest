#pragma once
#include <iostream>


struct Coord
{
    double x;
    double y;
    double z;
};

class Curve
{
    public:
    virtual void print(double t)=0;
    virtual void generateCenter()=0;
    virtual void generateRadius()=0;
    virtual double getX(double t) const=0;
    virtual double getY(double t) const=0;
    //virtual double getZ(double t) const;
    virtual double getDerivativeX(double t) const=0;
    virtual double getDerivativeY(double t) const=0;
    //virtual double getDerivativeZ(double t) const;
    //virtual double getRadius() const;
};
