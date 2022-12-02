#pragma once
#include "Circle.h"
#include "Square.h"
class CircleInSq :
    public Circle, public Square
{
public:
    CircleInSq();
    ~CircleInSq();
    CircleInSq(double x, double y, double rad);
    CircleInSq(double seide);
};