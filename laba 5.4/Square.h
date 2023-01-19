#pragma once
#include "Position.h"
class Square :
    virtual public Position
{
protected:
    double c1[2];
    double c2[2];
    double c3[2];
    double c4[2];
public:
    Square();
    ~Square();
    Square(double x, double y, double side);
    void out();
};
