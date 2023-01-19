#include "Position.h"
#include <iostream>
#include <random>

Position::Position()
{
	this->x = 0;
	this->y = 0;
}

Position::~Position()
{
}

Position::Position(int z)
{
	this->getrandom();
}

Position::Position(double x, double y)
{
	this->x = x;
	this->y = y;
}

void Position::out()
{
	std::cout << x << ' ' << y << '\n';
}

void Position::getrandom()
{
	this->x = rand() % 10;
	this->y = rand() % 10;
}