#pragma once
class Position
{
protected:
	double x, y;
public:
	Position();
	~Position();
	Position(int z);
	Position(double x, double y);
	void out();
	void getrandom(); 
};
