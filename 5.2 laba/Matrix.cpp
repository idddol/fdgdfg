#include "Matrix.h"
#include <iostream>
Matrix::Matrix()
{
}

Matrix::Matrix(int row, int col)
{
	size_col = col;
	size_row = row;
	elem = new double[col * row];
	for (int i = 0; i < col * row; i++)
	{
		elem[i] = 0;
	}
}

Matrix::Matrix(int row, int col, const double* arr)
{
	if (elem != nullptr)
		delete[]elem;
	size_col = col;
	size_row = row;
	elem = new double[size_col * size_row];
	for (int i = 0; i < size_col * size_row; i++) elem[i] = arr[i];
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

Matrix::Matrix(const Matrix& temp)
{
	if (elem != nullptr)
		delete[]elem;
	this->size_col = temp.size_col;
	this->size_row = temp.size_row;
	elem = new double[size_col * size_row];
	for (int i = 0; i < size_col * size_row; i++) this->elem[i] = temp.elem[i];
}


Matrix::~Matrix()
{
	if (elem != nullptr)
		delete[]elem;
}

void Matrix::output() const
{
	int counter = 0;
	for (int i = 0; i < size_col * size_row; i++)
	{
		if (counter == size_col) {
			std::cout << '\n';
			counter = 0;
		}
		std::cout << elem[i] << ' ';
		counter++;
	}
	std::cout << '\n';
}

void Matrix::sum_matrix(const Matrix& temp)
{
	for (int i = 0; i < temp.size_col * temp.size_row; i++)
	{
		this->elem[i] = this->elem[i] + temp.elem[i];
	}
	//return Matrix();
}

Matrix Matrix::sum_matrix(const double* arr)
{
	Matrix out(*this);
	out.sum_matrix(Matrix(this->size_row, this->size_col, arr));
	return out;
}

void Matrix::mult_number(int number)
{
	for (int i = 0; i < size_col * size_row; i++)
	{
		this->elem[i] = this->elem[i] * number;
	}
	//return Matrix();
}

void Matrix::mult_matrix(const Matrix& temp)
{

	if ((this->get_col() == temp.get_row()))
	{
		Matrix out(this->size_row, temp.size_col);
		for (int i = 0; i < this->size_row; i++) {
			for (int j = 0; j < temp.size_col; j++) {
				for (int k = 0; k < this->size_col; k++) {
					out.elem[i * temp.size_col + j] = this->elem[i * this->size_col + k] * temp.elem[k * temp.size_col + j];
				}
			}
		}
		out.output();
		this->input(out.size_row, out.size_col, out.elem);
	}
	else {
		std::cout << "Enter Matrix input";
	}
}

Matrix Matrix::mult_matrix(const double* arr)
{
	Matrix out;
	if (sizeof(arr) % (sizeof(arr[0]) * this->size_col) == 0) {
		int rhs_cols = sizeof(arr) / (sizeof(arr[0]) * this->size_col);
		out.mult_matrix(Matrix(this->size_col, rhs_cols, arr));
	}
	return out;
}

double Matrix::trase() const
{
	double out = 0;
	for (int i = 0; i < this->size_col; i++) {
		out += this->get_elem(i, i);
	}
	return out;
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

void Matrix::input(int row, int col, double* arr)
{
	if (elem != nullptr)
		delete[]elem;
	size_col = col;
	size_row = row;
	elem = new double[size_col * size_row];
	for (int i = 0; i < size_col * size_row; i++) elem[i] = arr[i];
}

void Matrix::input()
{
	std::cout << "¬ведите число строк и столбцов ";
	std::cin >> size_row >> size_col;
	Matrix::input(size_row, size_col);
}