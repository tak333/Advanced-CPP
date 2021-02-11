#pragma once

#include <vector>
#include <iostream>

class Matrix {
private:
	class Proxy {
		std::vector<int>& a;
		const std::vector<int>& b;
	public:
		Proxy(std::vector<int>& arr);
		Proxy(const std::vector<int>& str_c, std::vector<int>& str);
		int& operator[](size_t col);
		int operator[](size_t col) const;
	};

	std::vector <std::vector<int>> arr;
public:
	Matrix(size_t rows, size_t cols);

	Matrix& operator*=(const double& number);

	bool operator==(const Matrix& a) const;
	bool operator!=(const Matrix& a) const;

	size_t getRows() const;
	size_t getColumns() const;

	Proxy operator[](size_t row);
	const Proxy operator[](size_t row) const;
};
