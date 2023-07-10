#pragma once
#include "circle.h"
#include "ellipse.h"
#include "helix.h"
#include <memory>
#include <vector>
class CurveContainer
{
    public:
    void pushShape(std::shared_ptr<Curve> shape);
    void getType();
    std::shared_ptr<Curve> popShape();
    void printCurve(double t);
    void sortContainer();
    void sortCirclesByRadius();
    std::shared_ptr<Curve> operator[](int index) {
        return shapeContainer[index];
    }
    int getSize() const;
    private:
    std::vector<std::shared_ptr<Curve>> shapeContainer;
};