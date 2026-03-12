#pragma once
#include <iostream>
#include <math.h>
#include <string>
#include <stdexcept>
using namespace std;
class MyMatrix
{
private:
	int _m, _n;
	double** _matrix;
public:
	MyMatrix(const MyMatrix& other);
	MyMatrix(int m, int n) throw (const char*);
	MyMatrix();
	~MyMatrix();
	MyMatrix operator+(const MyMatrix& other) throw (const char*);
	MyMatrix operator-(const MyMatrix& other) throw (const char*);
	MyMatrix operator*(const MyMatrix& other);
	MyMatrix operator*(double num);
	friend MyMatrix operator* (double num, const MyMatrix& other);
	MyMatrix& operator=(const MyMatrix& other);
	bool operator==(const MyMatrix& other)const;
	friend ostream& operator<<(ostream& os,const MyMatrix& other);
	friend istream& operator>>(istream& is,MyMatrix& other) throw(const char*);
	double*& operator[](int m) throw(const char*);
	operator double();
};

