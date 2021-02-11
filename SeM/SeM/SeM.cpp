// SeM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <cassert>
#include "matrix.h"

int main() {
	Matrix M(5, 3);

	const Matrix N(7, 7);

	assert(M.getRows() == 5);
	assert(M.getColumns() == 3 && "Columns");

	//assert(false);

	try {
		//int k = N[22][23];
		M[0][0] = 16;
		int k = N[1][1];
	}
	catch (std::out_of_range& e) {
		std::cout << e.what() << '\n';
	}

	M *= 5;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++)
			std::cout << M[i][j] << ' ';
		std::cout << '\n';
	}

	return 0;
}





/*

#include <vector>
#include <iostream>

using std::vector;

const double EPS = 1e-6;


class OutOfBoundsException : public std::exception {};
class SizeMismatchException : public std::exception {};


class Proxy;

class Matrix {
private:
	std::vector <std::vector<int>> arr;
public:
	size_t getRows(size_t row);
	size_t getColumns(size_t column);
	void print();
	Matrix();
	Matrix(size_t rows, size_t cols);

	Proxy operator[](size_t row);
	Proxy operator[](size_t row) const;

	Matrix& operator*=(const double& number);

	bool operator==(const Matrix& a) const;
	bool operator!=(const Matrix& a) const;

	// Your code goes here...

};

Matrix::Matrix() {
	arr.push_back(vector<int>(1));
}


Matrix::Matrix(size_t rows, size_t cols): arr(rows, vector<int>(cols)) { }

class Proxy {
	std::vector<int>& a;
	const std::vector<int>& b;
public:
	Proxy(std::vector<int>& arr); //конструктор
	Proxy(std::vector<int> arr, int); //конструктор
	int& operator[](size_t col);
	int operator[](size_t col) const;
};

Proxy::Proxy(std::vector<int>& str) :a(str), b(str) { //конструктор : 	a = str

}

Proxy::Proxy(std::vector<int> str, int):a(str), b(str) { //конструктор : 	a = str

}

int& Proxy::operator[](size_t col) {
	return a[col];
}

int Proxy::operator[](size_t col) const {
	return a[col];
}

Proxy Matrix::operator[](size_t row) {
	return Proxy(arr[row]);
}

Proxy Matrix::operator[](size_t row) const {
	return Proxy(arr[row], 0);
}

void Matrix::print() {

	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = 0; j < arr[0].size(); j++)
			std::cout << arr[i][j] << ' ';
		std::cout << std::endl;
	}
}

Matrix& Matrix::operator*=(const double& number) {

	for (size_t i = 0; i < arr.size(); i++)
		for (size_t j = 0; j < arr[0].size(); j++)
			arr[i][j] *= number;

	return *this;
}

bool Matrix::operator==(const Matrix& a) const {
	return true;
}

bool Matrix::operator!=(const Matrix& a) const {
	a[5][5];
	return true;
}

size_t Matrix::getRows(size_t row) {
	return 0;
}

size_t Matrix::getColumns(size_t column) {
	return 0;
}
*/




/*
int main() {
	char c = '?';
	char* ptr, ptr1;
	ptr1 = '2';
	ptr = &ptr1;

	char* adr = &c; //указатель - переменная, хранит адрес

	//adr = 0;

	std::cout << c << ' ';
	printf("%c", *adr);

	int* arr;

	arr = new int[10];

	delete[] arr;

	int** mtr = new int* [3];

	for (int i = 0; i < 3; i++)
		mtr[i] = new int[4];

	mtr[5][6] = 7;

	for (int i = 0; i < 3; i++)
		delete[] mtr[i];

	delete[] mtr;

	return 0;
}
*/













/*
struct str {
	str(int* arr, int M) { a = arr; str::M = M; }
	int* a;
	int M;
	int& operator[](int j) {
		if (j < 0 || j > M)
			throw std::out_of_range("no2!");
		return a[j];
	}

	//int& operator= (int ind) {
		//if (ind < 0 || ind > M)
			//throw std::out_of_range("no3!");
		//return a[ind];
	//}
};

class matrix {
	int** arr;
	int N, M;
public:
	str operator[](int i) {
		if (i < 0 || i > N)
			throw std::out_of_range("no1!");
		return str(arr[i], M);
	}
	matrix(int n, int m) {
		N = n;
		M = m;
		arr = new int* [N];
		for (int i = 0; i < N; i++)
			arr[i] = new int[M];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				arr[i][j] = i + j;
	}

	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				std::cout << arr[i][j] << ' ';
			std::cout << std::endl;
		}
	}
};

int main()
{
	matrix M(3, 4);
	try {
		M[1][7] = -1;
	}
	catch (std::out_of_range& e) {
		std::cout << e.what();
		std::cout << "WHAAAAT";
	}

	M.print();
	return 0;
}

*/

/*
// SeM.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cassert>

class matrix {
	struct str {
		int* a;
		int& operator[](int j) {
			return a[j];
		}
	};
	str* arr;
	int N, M;
public:
	str& operator[](int i) {
		if (i < 0 || i > N)
			throw std::out_of_range("no no no ");
		return arr[i];
	}
	matrix(int n, int m) {
		N = n;
		M = m;
		arr = new str[N];
		for (int i = 0; i < N; i++)
			arr[i].a = new int[M];

		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				arr[i][j] = i + j;
	}

	void print() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++)
				std::cout << arr[i][j] << ' ';
			std::cout << std::endl;
		}
	}
};

int main()
{
	matrix M(3, 4);
	try {
		M[7][7] = -1;
	}
	catch (std::out_of_range& e) {
		std::cout<<e.what();
		std::cout << "WHAAAAT";
	}

	M.print();
	return 0;
}

*/