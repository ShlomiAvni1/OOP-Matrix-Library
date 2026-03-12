#include "MyMatrix.h"

MyMatrix::MyMatrix(const MyMatrix& other)
{
	this->_m = other._m;
	this->_n = other._n;
	this->_matrix = new double* [other._m];
	for ( int i = 0; i < other._m; i++)
	{
		this->_matrix[i] = new double [other._n];
		for (int j = 0; j < _n; j++)
		{
			this->_matrix[i][j] = other._matrix[i][j];
		}
	}
}

MyMatrix::MyMatrix(int m, int n) throw (const char*)
{
	if (m < 1 || n < 1)
	{
		throw "INVALID ARGUMENT : rows and columns values must be > 1";
	}
	this->_m = m;
	this->_n = n;
	this->_matrix = new double* [m];
	for (int i = 0; i < m; i++)
	{
		this->_matrix[i] = new double[n];
		for (int j = 0; j < n; j++)
		{
			this->_matrix[i][j] = 0;
		}
	}
}

MyMatrix::MyMatrix()
{
	this->_m = 3;
	this->_n = 3;
	this->_matrix = new double* [3];
	for (int i = 0; i < 3; i++)
	{
		this->_matrix[i] = new double[3];
		for (int j = 0; j < 3; j++)
		{
			this->_matrix[i][j] = 0;
		}
	}
}

MyMatrix::~MyMatrix()
{
	for (int i = 0; i < this->_m; i++)
	{
		delete this->_matrix[i];
	}
	delete[] this->_matrix;
}

MyMatrix MyMatrix::operator+(const MyMatrix& other) throw (const char*)
{
	if (this->_m != other._m || this->_n != other._n)
	{
		throw "INVALID ARGUMENT : rows and columns values must be equal in order to sum";
	}
	MyMatrix result(this->_m,this->_n);
	for (int i = 0; i < result._m; i++)
	{
		for (int j = 0; j < result._n; j++)
		{
			result._matrix[i][j] = this->_matrix[i][j] + other._matrix[i][j];
		}
	}
	return result;
}

MyMatrix MyMatrix::operator-(const MyMatrix& other) throw (const char*)
{
	if (this->_m != other._m || this->_n != other._n)
	{
		throw "INVALID ARGUMENT : rows and columns values must be equal in order to sum";
	}
	MyMatrix result(this->_m, this->_n);
	for (int i = 0; i < result._m; i++)
	{
		for (int j = 0; j < result._n; j++)
		{
			result._matrix[i][j] = this->_matrix[i][j] - other._matrix[i][j];
		}
	}
	return result;
}

MyMatrix MyMatrix::operator*(const MyMatrix& other)
{
	if (this->_n != other._m)
	{
		throw "INVALID ARGUMENT : column value of the first matrix must be equal to rows value of the second matrix in order to multiply";
	}
	MyMatrix result(this->_m,other._n);
	for (int i = 0; i < result._m; i++)
	{
		for (int j = 0; j < result._n; j++)
		{
			for (int w = 0; w < this->_n; w++)
			{
				result._matrix[i][j] += this->_matrix[i][w] * other._matrix[w][j];
			}
		}
	}
	return result;
}

MyMatrix MyMatrix::operator*(double num)
{
	MyMatrix result(*this);
	for (int i = 0; i < this->_m; i++)
	{
		for (int j = 0; j < this->_n; j++)
			result._matrix[i][j] *= num;
	}
	return result;
}

MyMatrix& MyMatrix::operator=(const MyMatrix& other)
{
	if (this->_matrix != other._matrix)
	{
	delete[] this->_matrix;
	this->_m = other._m;
	this->_n = other._n;
	this->_matrix = new double* [other._m];
	for (int i = 0; i < other._m; i++)
	{
		this->_matrix[i] = new double[other._n];
		for (int j = 0; j < _n; j++)
		{
			this->_matrix[i][j] = other._matrix[i][j];
		}
	}
	}
	return *this;
}

bool MyMatrix::operator==(const MyMatrix& other) const
{
	if (this->_m != other._m || this->_n != other._n)
			return false;

	for (size_t i = 0; i < this->_m; ++i)
	{
		for (size_t j = 0; j < this->_n; ++j)
		{
			if (this->_matrix[i][j] != other._matrix[i][j])
				return false;
		}
	}

		return true;
}
double*& MyMatrix::operator[](int m) throw(const char*)
{
	if (m < 0|| m >= this->_m )
	{
		throw "INVALID ARGUMENT: the requsted line is outside of matrix range";
		cout << endl;
	}
	return(this->_matrix[m]);
}
MyMatrix::operator double()
{
	double result = 0;
	for (int i = 0; i < this->_m; i++)
	{
		for (int j = 0; j < this->_n; j++)
		{
			result += this->_matrix[i][j];
		}
	}
	return result;
}
MyMatrix operator*(double num, const MyMatrix& other)
{
	MyMatrix result(other);
	for (int i = 0; i < other._m; i++)
	{
		for (int j = 0; j < other._n; j++)
			result._matrix[i][j] *= num;
	}
	return result;
}

ostream& operator<<(ostream& os, const MyMatrix& other)
{
	for (int i = 0; i < other._m; i++)
	{
		os << "(";
		for (int j = 0; j < other._n; j++)
		{
			os << other._matrix[i][j];
			if (j != (other._n - 1))
			{
				os << ",";
			}
		}
		os << ")" << endl;
	}
	return os;
}

istream& operator>>(istream& is, MyMatrix& other) throw(const char*)
{
	cout << "Enter rows number:"<<endl;
	is >> other._m;
	cout << "Enter cols number:" << endl;
	is >> other._n;
	if (other._m < 1 || other._n < 1)
	{
		other._m = 0;
		other._n = 0;
		throw "INVALID ARGUMENT: rows and cols number must be > 1";
		cout << endl;
	}
	if (other._matrix)
		delete other._matrix;
	other._matrix = new double* [other._m];
	cout << "Enter " << (other._m*other._n) << " matrix numbers"<<endl;
	for (int i = 0; i < other._m; i++)
	{
		other._matrix[i] = new double[other._n];
		for (int j = 0; j < other._n; j++)
		{
			is>>other._matrix[i][j];
		}
	}
	return is;
}
