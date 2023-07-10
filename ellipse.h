#pragma once
#include "curve.h"
#include <vector>
class Ellipse : public Curve
{
    public:
    void print(double t);
    void generateCenter();
    void generateRadius();
    double getX(double t) const;
    double getY(double t) const;
    double getDerivativeX(double t) const;
    double getDerivativeY(double t) const;
    Ellipse();
    double getRadius() const;
    
    private:
    std::vector<Coord> Figure;
    Coord Center;
    double X_Rad;
    double Y_Rad;
};
