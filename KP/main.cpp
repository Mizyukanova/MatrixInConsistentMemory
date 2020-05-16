// KP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Matrix.cpp"
using namespace std;

int main()
{
	Matrix<int> A(3,1);
	A.At(0, 0) = 5;
	Matrix<int> B(2,2);
	Matrix<int> C(3,2);
	try
	{
		C = A + B;
	}
	catch (Matrix<int>::DifferentDimensionsException)
	{
		cout << "Error: Matrices of different dimensions." << endl;
	}
}