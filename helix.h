#pragma once
#include "curve.h"

class Helix : public Curve
{
    public:
    void print(double t);
    Helix();
    void generateCenter();
    void generateRadius();
    void generateStep();
    double getX(double t) const;
    double getY(double t) const;
    double getZ(double t) const;
    double getDerivativeX(double t) const;
    double getDerivativeY(double t) const;
    double getDerivativeZ(double t) const;
    double getRadius() const;
    private:
    Coord Center;
    double Rad;
    double step;
};
