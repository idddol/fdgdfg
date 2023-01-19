#include "Circle.h"
#include <iostream>

Circle::Circle()
{
	this->rad = 0;
}

Circle::~Circle()
{
}

Circle::Circle(double x, double y, double rad):Position(x,y)
{
	this->x = x;
	this->y = y;
	this->rad = rad;
}

void Circle::out()
{
	std::cout << '\n' << x << ' ' << y << ' ' << rad << '\n';
}