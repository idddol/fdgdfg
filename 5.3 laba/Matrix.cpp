#include "Matrix.h"
#include <iostream>

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
}

Matrix::~Matrix()
{
	if (elem != nullptr)
		delete[]elem;
}

Matrix::Matrix(const int size_rows)
{
	setlocale(LC_ALL, "Russian");
	rows = size_rows;
	cols = size_rows;
	if (elem != nullptr)
		delete[]elem;
	elem = new double[size_rows * 3];
	std::cout << "Ââĺäčňĺ ýëĺěĺíňű ěŕňđčöű ";
	for (int i = 0; i < cols * 3; i++)
	{
		std::cin >> elem[i];
	}
	elem[rows - 1] = 0;
	elem[rows * 2] = 0;
}

double Matrix::get_elem(int i, int j) const
{
	if (i == j) return elem[rows + i];
	else if (i == j + 1) return elem[rows * 2 + i];
	else if (i + 1 == j) return elem[i];
	else return 0;
}

void Matrix::output() const
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << this->get_elem(i, j) << " ";
		}
		std::cout << '\n';
	}
}

double Matrix::trase()
{
	double out = 0;
	for (int i = 0; i < this->cols; i++) {
		out += this->get_elem(i, i);
	}
	return out;
}

int Matrix::columns()
{
	return rows;
}

void Matrix::input(int size)
{
	setlocale(LC_ALL, "Russian");
	rows = size;
	cols = size;
	if (elem != nullptr)
		delete[]elem;
	std::cout << "Ââĺäčňĺ ěŕňđčöó ";
	elem = new double[size * 3];
	for (int i = 0; i < size * 3; i++)
	{
		if (i != rows - 1 or i != rows * 2)
			std::cin >> elem[i];
		else elem[i] = 0;
	}
}

void Matrix::copy(const Matrix& temp)
{
	if (elem != nullptr)
		delete[]elem;
	elem = new double[temp.cols * 3];
	this->cols = temp.cols;
	this->rows = temp.rows;
	for (int i = 0; i < temp.cols * 3; i++) this->elem[i] = temp.elem[i];
}

void Matrix::operator+=(Matrix& temp)
{
	for (int i = 0; i < temp.rows * 3; i++) {
		this->elem[i] += temp.elem[i];
	}
}

void Matrix::operator-=(Matrix& temp)
{
	for (int i = 0; i < temp.rows * 3; i++) {
		this->elem[i] -= temp.elem[i];
	}
}

void Matrix::operator=(const Matrix& temp)
{
	this->copy(temp);
}

void Matrix::operator+(Matrix& right)
{
	Matrix out;
	out = right;
	for (int i = 0; i < right.cols * 3; i++)
	{
		out.elem[i] = this->elem[i] + right.elem[i];
	}
	std::cout << out;
}

void Matrix::operator-(Matrix& right)
{
	Matrix out;
	out = right;
	for (int i = 0; i < right.cols * 3; i++)
	{
		out.elem[i] = this->elem[i] - right.elem[i];
	}
	std::cout << out;
}


void Matrix::operator*(double k)
{
	for (int i = 0; i < rows * 3; i++) elem[i] *= k;
}


void Matrix::input()
{
	setlocale(LC_ALL, "Russian");
	int size;
	std::cout << "Ââĺäčňĺ đŕçěĺđ ěŕňđčöű ";
	std::cin >> size;
	this->input(size);
}

std::istream& operator>>(std::istream& input, Matrix& temp)
{
	int size;
	setlocale(LC_ALL, "Russian");
	std::cout << "Ââĺäčňĺ đŕçěĺđ ěŕňđčöű ";
	input >> size;
	/*temp.rows = size;
	temp.cols = size;
	if (temp.elem != nullptr)
		delete[]temp.elem;
	temp.elem = new double[size * 3];
	for (int i = 0; i < size * 3; i++)
	{
		temp.elem[i] = i + 1;
	}
	temp.elem[temp.rows - 1] = 0;
	temp.elem[temp.rows * 2] = 0;*/
	temp.input(size);
	return input;
}

void operator-(Matrix& left)
{
	for (int i = 0; i < left.cols * 3; i++) left.elem[i] *= -1;
	left.output();
}

/*Matrix operator*(Matrix& left, Matrix& right)
{
	if ((left.cols == right.rows))
	{
		D3Matrix out;
		out = left;
		for (int i = 0; i < left.rows; i++) {
			for (int j = 0; j < right.cols; j++) {
				for (int k = 0; k < left.cols; k++) {
					out.elem[i * left.cols + j] += left.elem[i * left.cols + k] * right.elem[k * right.cols + j];
				}
			}
		}
		out.output();
	}
	else {
		std::cout << "Enter Matrix input";
		if (left.elem != nullptr)
			delete[]left.elem;
		if (right.elem != nullptr)
			delete[]right.elem;
		std::abort();
	}
	return Matrix();
}*/

std::ostream& operator<<(std::ostream& out, const Matrix& temp)
{
	for (int i = 0; i < temp.rows; i++) {
		for (int j = 0; j < temp.rows; j++) {
			out << temp.get_elem(i, j) << " ";
		}
		out << '\n';
	}
	return out;
}