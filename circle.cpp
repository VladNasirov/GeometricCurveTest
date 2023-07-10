#include "circle.h"
#include <random>

Circle::Circle()
{
    generateCenter();
    generateRadius();
}

void Circle::generateCenter()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-10.0f, 10.0f);
    Center.z=0;
    Center.x=dis(gen);
    Center.y=dis(gen);
}

void Circle::generateRadius()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 10.0f);

    Rad = dis(gen);
}

double Circle::getX(double t) const
{
    return Center.x + Rad * cos(t);
}
double Circle::getY(double t) const
{
    return Center.y + Rad * sin(t);
}

double Circle::getDerivativeX(double t) const {
        return -Rad * sin(t);
    }

double Circle::getDerivativeY(double t) const {
        return Rad * cos(t);
}

void Circle::print(double t)
{
    std::cout<<"Shape type: Circle"<<std::endl;
    std::cout<<"Coordinates (x;y;z) at "<<t<<":"<<std::endl;
    //TODO цикл до 2PI
    std::cout<<"("<<getX(t)<<";"<<getY(t)<<";"<<Center.z<<")"<<std::endl;
    std::cout<<"Derivative:"<<std::endl;
    // производная z 0
    std::cout<<"("<<getDerivativeX(t)<<";"<<getDerivativeY(t)<<";"<<Center.z<<")"<<std::endl;
    std::cout<<"Radius: "<<getRadius()<<std::endl;
    std::cout<<std::endl;
}

double Circle::getRadius() const
{
    return Rad;
}