#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	size_row = 0;
	size_col = 0;
}

Matrix::~Matrix()
{
	if (elem != nullptr)
		delete[]elem;
}

Matrix::Matrix(const Matrix& temp)
{
	this->size_col = temp.size_col;
	this->size_row = temp.size_row;
	elem = new double[size_col * size_row];
	for (int i = 0; i < size_col * size_row; i++) this->elem[i] = temp.elem[i];
}

Matrix::Matrix(int size)
{
	size_col = size;
	size_row = size;
	elem = new double[size * size];
	for (int i = 0; i < size * size; i++)
	{
		elem[i] = 0;
	}
}

Matrix::Matrix(int r, int c)
{

	size_col = c;
	size_row = r;
	elem = new double[r * c];
	for (int i = 0; i < r * c; i++)
	{
		elem[i] = 0;
	}
}


double Matrix::get_elem(int i, int j) const
{
	return elem[i*size_col+j];
}

void Matrix::output() const
{
	for (int i = 0; i < size_row; i++) {
		for (int j = 0; j < size_row; j++) {
			std::cout << this->get_elem(i, j) << " ";
		}
		std::cout << '\n';
	}
}

double Matrix::trase()
{
	double out = 0;
	for (int i = 0; i < this->size_col; i++) {
		out += this->get_elem(i, i);
	}
	return out;
}

void Matrix::input(int size)
{
	setlocale(LC_ALL, "Russian");
	size_row = size;
	size_col = size;
	if (elem != nullptr)
		delete[]elem;
	std::cout << "Введите значения ";
	elem = new double[size * 2];
	for (int i = 0; i < size * 2; i++)
	{
		if (i != size_row - 1 or i != size_row * 2)
			std::cin >> elem[i];
		else elem[i] = 0;
	}
}

void Matrix::copy(const Matrix& temp)
{
	if (elem != nullptr)
		delete[]elem;
	elem = new double[temp.size_col * size_row];
	this->size_col = temp.size_col;
	this->size_row = temp.size_row;
	for (int i = 0; i < temp.size_col * size_row; i++) this->elem[i] = temp.elem[i];
}

void Matrix::operator+=(Matrix& temp)
{
	for (int i = 0; i < temp.size_row * size_col; i++) {
		this->elem[i] += temp.elem[i];
	}
}

void Matrix::operator-=(Matrix& temp)
{
	this->sum_matrix(temp*(-1));
	/*for (int i = 0; i < temp.size_row * size_col; i++) {
		this->elem[i] -= temp.elem[i];
	}*/
}

void Matrix::operator=(const Matrix& temp)
{
	this->copy(temp);
}

void Matrix::operator-()
{
	this->mult_number(-1);
}

void Matrix::input(int row, int col)
{
	size_col = col;
	size_row = row;
	elem = new double[col * row];
	for (int i = 0; i < col * row; i++)
	{
		elem[i] = 0;
	}
}

void Matrix::input()
{
	std::cout << "Введите размеры матрицы ";
	std::cin >> size_row >> size_col;
	Matrix::input(size_row, size_col);
}

std::istream& operator>>(std::istream& input, Matrix& temp)
{
	int size;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите размер ";
	input >> size;
	temp.input(size);
	return input;
}

/*Matrix Matrix::operator-() {
	Matrix mat3(size);
	int t;
	for (int i = 0; i < size * size; i++) {
		if (elem[i] != 0) {
			t = -elem[i];
			mat3.elem[i] = t;
		}
	}
	std::cout << "Матрица с измененными знаками: \n";
	mat3.output();
	return mat3;
}*/

void Matrix::mult_matrix(const Matrix& temp)
{
	if ((this->size_col == temp.size_row))
	{
		Matrix out(this->size_row, temp.size_col);
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < temp.size_col; j++) {
				out.elem[i * out.size_col + j] = 0;
				for (int k = 0; k < this->size_col; k++) {
					out.elem[i * out.size_col + j] += this->elem[i * this->size_col + k] * temp.elem[k * temp.size_col + j];
				}
			}
		}
		out.output();
	}
	else {
		std::cout << "Enter Matrix input";
		if (this->elem != nullptr)
			delete[]this->elem;
		if (temp.elem != nullptr)
			delete[]temp.elem;
		std::abort();
	}
}

std::ostream& operator<<(std::ostream& out, const Matrix& temp)
{
	for (int i = 0; i < temp.size_row; i++) {
		for (int j = 0; j < temp.size_row; j++) {
			out << temp.get_elem(i, j) << " ";
		}
		out << '\n';
	}
	return out;
}

void Matrix::sum_matrix(const Matrix& temp)
{
	for (int i = 0; i < temp.size_col * temp.size_row; i++)
	{
		this->elem[i] = this->elem[i] + temp.elem[i];
	}
	//return Matrix();
}
/*
void Matrix::raz_matrix(const Matrix& temp)
{
	for (int i = 0; i < temp.size_col * temp.size_row; i++)
	{
		this->elem[i] = this->elem[i] - temp.elem[i];
	}
}
*/
Matrix& operator*(const Matrix& left, const Matrix& right)
{
	Matrix res(left);
	res.mult_matrix(right);
	return res;
}

Matrix& operator*(const Matrix& left, double num)
{
	Matrix res(left);
	res.mult_number(num);
	return res;
}

Matrix& operator+(const Matrix& left, const Matrix& right)
{
	Matrix res(left);
	res.sum_matrix(right);
	return res;
}

Matrix& operator-(const Matrix& left, const Matrix& right)
{
	Matrix res(left);
	res.sum_matrix(right*(-1));
	return res;
}

void Matrix::mult_number(double number)
{
	for (int i = 0; i < size_col * size_row; i++)
	{
		this->elem[i] = this->elem[i] * number;
	}
	//return Matrix();
}