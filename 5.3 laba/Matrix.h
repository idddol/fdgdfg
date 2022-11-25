#pragma once
#include <iostream>
class Matrix
{
private:
	int rows, cols;
	double* elem;
public:
	Matrix();
	~Matrix();
	Matrix(const int size_rows);
	double get_elem(int i, int j) const;
	void output() const;
	double trase();
	int columns();
	void input();
	void input(int size);
	void copy(const Matrix& temp);
	void operator+=(Matrix& temp);
	void operator=(const Matrix& temp);
	void operator+(Matrix& right);
	void operator-(Matrix& right);
	void operator*(double k);
	void operator-=(Matrix& temp);

	friend void operator-(Matrix& left);
	friend std::istream& operator>>(std::istream& input, Matrix& temp);
	friend std::ostream& operator<<(std::ostream& out, const Matrix& temp);
};
