#pragma once
#include "Position.h"
class Circle :
    virtual public Position
{
protected:
    double rad;
public:
    Circle();
    ~Circle();
    Circle(double x, double y, double rad);
    void out();
};
