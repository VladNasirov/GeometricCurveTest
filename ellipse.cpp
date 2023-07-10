#include "ellipse.h"
#include <random>

Ellipse::Ellipse()
{
    generateCenter();
    generateRadius();
}

void Ellipse::generateCenter()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(-10.0f, 10.0f);
    Center.z=0;
    Center.x=dis(gen);
    Center.y=dis(gen);
}

void Ellipse::generateRadius()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 10.0f);

    X_Rad = dis(gen);
    Y_Rad = dis(gen);
    while(Y_Rad==X_Rad)
    {
        Y_Rad=dis(gen);
    }
}

double Ellipse::getX(double t) const
{
    return Center.x + X_Rad * cos(t);
}
double Ellipse::getY(double t) const
{
    return Center.y + Y_Rad * sin(t);
}

double Ellipse::getDerivativeX(double t) const {
        return -X_Rad * sin(t);
    }

double Ellipse::getDerivativeY(double t) const {
        return -Y_Rad * cos(t);
}

void Ellipse::print(double t)
{
    std::cout<<"Shape type: Ellipse"<<std::endl;
    std::cout<<"Coordinates (x;y;z) at "<<t<<":"<<std::endl;
    //TODO цикл до 2PI
    std::cout<<"("<<getX(t)<<";"<<getY(t)<<";"<<Center.z<<")"<<std::endl;
    std::cout<<"Derivative:"<<std::endl;
    // производная z 0
    std::cout<<"("<<getDerivativeX(t)<<";"<<getDerivativeY(t)<<";"<<Center.z<<")"<<std::endl;
}