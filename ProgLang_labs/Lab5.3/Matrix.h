#pragma once
#include <iostream>
class Matrix
{
private:
	int size_row,size_col;
	double* elem;
public:
	Matrix();
	~Matrix();
	Matrix(const int len);
	Matrix(int r,int c);
	Matrix(const Matrix& temp);
	double get_elem(int i, int j) const;
	void output() const;
	double trase();
	void input();
	void input(int row, int col);
	void input(int size);
	void copy(const Matrix& temp);
	void operator+=(Matrix& temp);
	void operator=(const Matrix& temp);
	void operator-();
	void operator-=(Matrix& temp);//перегрузка как метод класса, т.к. меняет текущий объект

	friend std::istream& operator>>(std::istream& input, Matrix& temp);//перегрузка вне класса, но как дружественный, т.к. не меняет текущий объект, но ему нужен доступ к приватным свойствам
	friend std::ostream& operator<<(std::ostream& out, const Matrix& temp);

	void sum_matrix(const Matrix& temp);
	//void raz_matrix(const Matrix& temp);
	void mult_number(double number);
	void mult_matrix(const Matrix& temp);
	int get_row() { return size_row; }
	int get_col() { return size_col; }
};

Matrix& operator+(const Matrix& left, const Matrix& right); //перегрузка вне класса, т.к. не меняет текущий объект
Matrix& operator-(const Matrix& left, const Matrix& right);
Matrix& operator*(const Matrix& left, const Matrix& right);
Matrix& operator*(const Matrix& left, double num);