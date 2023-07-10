#include "CurveContainer.h"
#include <algorithm>

void CurveContainer::pushShape(std::shared_ptr<Curve> shape)
{
    shapeContainer.push_back(shape);
}
int CurveContainer::getSize() const
{
    return shapeContainer.size();
}

bool compareByRadius(std::shared_ptr<Curve> circle1, std::shared_ptr<Curve> circle2) {
    std::shared_ptr<Circle> cir1 = std::dynamic_pointer_cast<Circle>(circle1);
    std::shared_ptr<Circle> cir2 = std::dynamic_pointer_cast<Circle>(circle2);
    return cir1->getRadius() < cir2->getRadius();
}

void CurveContainer::sortCirclesByRadius()
{
    std::sort(shapeContainer.begin(), shapeContainer.end(), compareByRadius);
}


std::shared_ptr<Curve> CurveContainer::popShape()
{
    std::shared_ptr<Curve> shape=shapeContainer.back();
    shapeContainer.pop_back();
    return shape;
    
}

void CurveContainer::printCurve(double t)
{
    for(const auto& shape : shapeContainer)
    {
        shape->print(t);
    }
}
