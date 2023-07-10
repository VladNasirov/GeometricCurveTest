#include "CurveContainer.h"
#include <iostream>
#include <random>
#include <cmath>
#include <omp.h>
void populateContainer(CurveContainer& c);
void populateCirclesContainer(CurveContainer& cir, CurveContainer& curves);
double ComputeRadiusSum(CurveContainer& circ);
int main()
{
    CurveContainer cont;
    CurveContainer circles;
    populateContainer(cont);
    double t=M_PI_4;
    cont.printCurve(t);
    populateCirclesContainer(circles, cont);

    std::cout<<std::endl;
    if(circles.getSize()>0)
    {
    std::cout<<"Circles :"<<std::endl;
    circles.sortCirclesByRadius();
    circles.printCurve(t);

    std::cout<<"Total radius: "<<ComputeRadiusSum(circles) <<std::endl;
    }
    else
    {
        std::cout<<"No circles in shapesContainer!"<<std::endl;
    }

    return 0;
}

void populateContainer(CurveContainer& c)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 100);
    int amount_of_elements=dis(gen);
    std::cout<<"Amount of elements: "<<amount_of_elements<<std::endl;

    std::uniform_int_distribution<int> t(1, 3);
    int CircCounter=0, EllipseCounter=0, HelixCounter=0;
    for(int i=0; i<amount_of_elements; i++)
    {
        int type=t(gen);
        switch (type)
        {
            case 1:
            {
                CircCounter++;
                std::shared_ptr<Circle> cir=std::make_shared<Circle>();
                c.pushShape(cir);
                break;
            }
            case 2:
            {
                EllipseCounter++;
                std::shared_ptr<Ellipse> elip=std::make_shared<Ellipse>();
                c.pushShape(elip);
                break;
            }
            case 3:
            {
                HelixCounter++;
                std::shared_ptr<Helix> hel=std::make_shared<Helix>();
                c.pushShape(hel);
                break;
            }
        }
    }
    std::cout<<"Number of Circles: "<<CircCounter<<std::endl;
    std::cout<<"Number of Ellipses: "<<EllipseCounter<<std::endl;
    std::cout<<"Number of Helixes: "<<HelixCounter<<std::endl;
}

void populateCirclesContainer(CurveContainer& cir, CurveContainer& curves)
{
    for(int i=0; i<curves.getSize(); i++)
    {
        std::shared_ptr<Circle> circl = std::dynamic_pointer_cast<Circle>(curves[i]);
        if (circl) 
        {
        std::shared_ptr<Curve> circl1 = std::dynamic_pointer_cast<Curve>(circl);
        cir.pushShape(circl1);
        }
        else
        {

        }
    }
}

double ComputeRadiusSum(CurveContainer& circ)
{
    double totalRadius=0;
    #pragma omp parallel for
    for(int i=0; i<circ.getSize(); i++)
    {
        #pragma omp critical
        {
        std::shared_ptr<Circle> circl = std::dynamic_pointer_cast<Circle>(circ[i]);
        totalRadius+=circl->getRadius();
        }
    }
    return totalRadius;
}