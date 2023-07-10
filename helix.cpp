#include "helix.h"
#include <random>

Helix::Helix()
{
    generateCenter();
    generateRadius();
    generateStep();
}

void Helix::generateCenter()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-10.0f, 10.0f);
    Center.z=dis(gen);
    Center.x=dis(gen);
    Center.y=dis(gen);
}
 void Helix::generateStep()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 5.0f);
    step=dis(gen);
}
void Helix::generateRadius()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 10.0f);

    Rad = dis(gen);
}

double Helix::getX(double t) const
{
    return Center.x + Rad * cos(t);
}
double Helix::getY(double t) const
{
    return Center.y + Rad * sin(t);
}
double Helix::getZ(double t) const
{
    return step*t;
}

double Helix::getDerivativeX(double t) const 
{
        return -Rad * sin(t);
}

double Helix::getDerivativeY(double t) const 
{
        return Rad * cos(t);
}
double Helix::getDerivativeZ(double t) const 
{
        return step;
}

void Helix::print(double t)
{
    std::cout<<"Shape type: Helix"<<std::endl;
    std::cout<<"Coordinates (x;y;z) at "<<t<<":"<<std::endl;
    //TODO цикл до 2PI
    std::cout<<"("<<getX(t)<<";"<<getY(t)<<";"<<getZ(t)<<")"<<std::endl;
    std::cout<<"Derivative:"<<std::endl;
    // производная z 0
    std::cout<<"("<<getDerivativeX(t)<<";"<<getDerivativeY(t)<<";"<<getDerivativeZ(t)<<")"<<std::endl;
}

double Helix::getRadius() const
{
    return Rad;
}