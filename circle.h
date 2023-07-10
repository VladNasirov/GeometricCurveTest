#pragma once
#include "curve.h"

class Circle : public Curve
{
    public:
    void print(double t);
    Circle();
    void generateCenter();
    void generateRadius();
    double getX(double t) const;
    double getY(double t) const;
    double getDerivativeX(double t) const;
    double getDerivativeY(double t) const;
    double getRadius() const;
    private:
    Coord Center;
    double Rad;
};
