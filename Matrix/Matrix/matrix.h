#pragma once

#include <vector>
#include <iostream>


namespace task {

    class Proxy {
        double* ptr;
        size_t cols;
    public:
        Proxy(double* ptr, size_t rows);
        double& operator[](size_t col);
        double operator[](size_t col) const;
    };

    const double EPS = 1e-6;


    class OutOfBoundsException : public std::exception {};
    class SizeMismatchException : public std::exception {};


    class Matrix {
    private:
        double** arr;
        size_t rows, cols;
    public:
        Matrix();
        Matrix(size_t rows, size_t cols);
        Matrix(const Matrix& copy);
        Matrix& operator=(const Matrix& a);

        double& get(size_t row, size_t col);
        const double& get(size_t row, size_t col) const;
        void set(size_t row, size_t col, const double& value);
        void resize(size_t new_rows, size_t new_cols);

        Proxy operator[](size_t row);
        const Proxy operator[](size_t row) const;

        Matrix& operator+=(const Matrix& a);
        Matrix& operator-=(const Matrix& a);
        Matrix& operator*=(const Matrix& a);
        Matrix& operator*=(const double& number);

        Matrix operator+(const Matrix& a) const;
        Matrix operator-(const Matrix& a) const;
        Matrix operator*(const Matrix& a) const;
        Matrix operator*(const double& a) const;

        Matrix operator-() const;
        Matrix operator+() const;

        double det() const;
        void transpose();
        Matrix transposed() const;
        double trace() const;

        std::vector<double> getRow(size_t row);
        std::vector<double> getColumn(size_t column);

        bool operator==(const Matrix& a) const;
        bool operator!=(const Matrix& a) const;

        size_t getRows() const;
        size_t getCols() const;

    private:
        void getCofactor(double** mat, double** temp, int p, int q, int n) const;
        double determinantOfMatrix(double** mat, int n) const;
    };

    Matrix operator*(const double& a, const Matrix& b);

    std::ostream& operator<<(std::ostream& output, const Matrix& matrix);
    std::istream& operator>>(std::istream& input, Matrix& matrix);


}  // namespace task