#include "MyMatrix.h"
void main()
{
	MyMatrix m1, m2, m3, m4, m5, m6, m7, m8;//default c'tor
	try
	{
		cout << "Matrix m1: default "<<endl << m1 << endl;//cout op'tor + defalut c'tor realization
		cout << "For matrix m1 : " << endl;
		cin >> m1;
		double sum1 = (double)m1;
		cout << "Matrix m1: " << endl << m1 << endl;//cout op'tor 
		cout << "Sum of all Matrix1 elements: " << endl;
		cout << sum1 << endl;

		cout << "******************************************************************" << endl;

		m2 = MyMatrix(4, 3);//c'tor
		cout << "Matrix m2: " << endl << m2 << endl;//c'tor realization
		cout << "For matrix m2 : " << endl;
		cin >> m2;
		double sum2 = (double)m2;
		cout << "Matrix m2: " << endl << m2 << endl;//cout op'tor 
		cout << "Sum of all Matrix2 elements: " << endl;
		cout << sum2 << endl;

		cout << "******************************************************************" << endl;

		cout << "For matrix m3: " << endl;
		cin >> m3;
		double sum3 = (double)m3;
		cout << "Matrix m3: " << endl << m3 << endl;//cout op'tor 
		cout << "Sum of all Matrix3 elements: " << endl;
		cout << sum3 << endl;

		cout << "******************************************************************" << endl;
	}
	catch (const char* m)
	{
		cout << "ERROR: " << m << endl;
	}
	try //operator[]realization
	{
		double x1 = m1[1][2];
		cout << "Matrix1 element at index [2][3]:" << endl;
		cout << x1 << endl;
		double x2 = m2[3][2];
		cout << "Matrix2 element at index [4][3]:" << endl;
		cout << x2 << endl;
		double x3 = m3[0][0];
		cout << "Matrix3 element at index [1][1]:" << endl;
		cout << x3 << endl;
	}

	catch (const char* m)
	{
		cout << "ERROR: " << m << endl;
	}

	cout << "******************************************************************" << endl;
	try 
	{
		m4 = m1 * m2;
		cout << "Matrix4 = Matrix1 * Matrix2: " << endl;
		cout << m4;
		if (m4 == m2) {
			cout << "Matrix4 is the same as Matrix2" << endl;
		}
		else {
			cout << "Matrix4 is different from Matrix2" << endl;
		}
	}
	catch (const char* m)
	{
		cout << "ERROR: " << m << endl;
	}

	cout << "******************************************************************" << endl;

	try  
	{
		m5 = m3 + m4;
		cout << "Matrix5 = Matrix3 + Matrix4: " << endl;
		cout << m5;
		cout << "******************************************************************" << endl << endl;
		m6 = m5 + m4 - m3;
		cout << "Matrix6 = Matrix5 + Matrix4 - Matrix3: " << endl;
		cout << m6;
		cout << "******************************************************************" << endl << endl;
		m7 = m6 * 9.0;
		cout << "Matrix7 = Matrix6 * 9.0 : " << endl;
		cout << m7;
		cout << "******************************************************************" << endl << endl;
		m8 = 5.6 * m6;
		cout << "Matrix8 = 5.6 * Matrix6 :" << endl;
		cout << m8;
		cout << "******************************************************************" << endl << endl;
		m2 = m6;
		cout << "Placement of Matrix6 in Matrix2 :" << endl;
		cout << m2;
	}

	catch (const char* m)
	{
		cout << "ERROR: " << m << endl;
	}
}


