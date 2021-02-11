#include "matrix.h"

Matrix::Matrix(size_t rows, size_t cols) : arr(rows, std::vector<int>(cols)) {}

Matrix::Proxy::Proxy(std::vector<int>& str) : a(str), b(str) {}

Matrix::Proxy::Proxy(const std::vector<int>& str_c, std::vector<int>& str) : b(str_c), a(str) {}

int& Matrix::Proxy::operator[](size_t col) {
	if (col < 0 || col >= a.size())
		throw std::out_of_range("");
	return a[col];
}

int Matrix::Proxy::operator[](size_t col) const {
	if (col < 0 || col >= b.size())
		throw std::out_of_range("");
	return b[col];
}

Matrix::Proxy Matrix::operator[](size_t row) {
	if (row < 0 || row >= arr.size())
		throw std::out_of_range("");
	return Proxy(arr[row]);
}

const Matrix::Proxy Matrix::operator[](size_t row) const {
	if (row < 0 || row >= arr.size())
		throw std::out_of_range("");
	std::vector<int> temp;
	return Proxy(arr[row], temp);
}

Matrix& Matrix::operator*=(const double& number) {
	for (size_t i = 0; i < arr.size(); i++)
		for (size_t j = 0; j < arr[0].size(); j++)
			arr[i][j] *= number;

	return *this;
}

bool Matrix::operator==(const Matrix& a) const {
	if (arr.size() == a.arr.size() &&
		arr[0].size() == a.arr[0].size()) {
		for (size_t i = 0; i < arr.size(); i++)
			for (size_t j = 0; j < arr[0].size(); j++)
				if (arr[i][j] != a.arr[i][j])
					return false;
	}
	else
		return false;

	return true;

}

bool Matrix::operator!=(const Matrix& a) const {
	if (arr.size() != a.arr.size() ||
		arr[0].size() != a.arr[0].size())
		return true;

	for (size_t i = 0; i < arr.size(); i++)
		for (size_t j = 0; j < arr[0].size(); j++)
			if (arr[i][j] != a.arr[i][j])
				return true;

	return false;
}

size_t Matrix::getRows() const {
	return arr.size();
}

size_t Matrix::getColumns() const {
	return arr[0].size();
}