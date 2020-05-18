#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
private:

	int rowCount; //���������� ����� �������
	int columnCount; //���������� �������� �������
	T* dataPointer; // ��������� �� ������� ������, ���������� ������������������ ��������� �������

public:

	class DifferentDimensionsException {}; // ����� ����������, ��� �������� ������ ������ ������������
	class ArgumentsCountException {}; // ����� ����������, ��� �������� ������ ��� ����� ���������� ����������

	Matrix() // ����������� ��-���������
	{
		dataPointer = nullptr;
		rowCount = 0;
		columnCount = 0;
		cout << "Address of created object(1): " << this << endl;
	}

	Matrix(int row, int col) // ����������� � �����������, ��� row - ���������� �����, � col - ���������� ��������
	{
		rowCount = row;
		columnCount = col;
		dataPointer = new T[row * col];
		T defaultValue = T();
		for (int i = 0; i < row * col; i++)
		{
			*(dataPointer + i) = defaultValue;
		}
		cout << "Address of created object(2): " << this << endl;
	}

	Matrix(int row, int col, T value) // ����������� � �����������, ��� row - ���������� �����, col - ���������� ��������, � value - ��������, ������� ���������� ��� �������
	{
		rowCount = row;
		columnCount = col;
		dataPointer = new T[row * col];
		for (int i = 0; i < row * col; i++)
		{
			*(dataPointer + i) = value;
		}
		cout << "Address of created object(3): " << this << endl;
	}

	Matrix(const Matrix& inputMatrix) // ����������� �����������
	{
		rowCount = inputMatrix.rowCount;
		columnCount = inputMatrix.columnCount;
		dataPointer = new T[rowCount * columnCount];

		for (int i = 0; i < rowCount * columnCount; i++)
		{
			*(dataPointer + i) = *(inputMatrix.dataPointer + i);
		}
		cout << "Address of created object(4): " << this << endl;
	}

	~Matrix() // ����������
	{
		cout << "Address of deleted object: " << this << endl;
		delete[] dataPointer;
	}

	Matrix<T> operator+(const Matrix<T>& secondVector); // �������� ������������ ������	

	Matrix<T> operator-(const Matrix<T>& secondMatrix); // �������� ��������� ������

	Matrix<T> operator*(const double constant); // �������� ��������� ������� �� �����

	Matrix<T> operator*(Matrix<T>& secondMatrix); // �������� ������������ ������

	T& At(int i, int j); // �������� ��������� � �������� �������� ������� �� �������

	Matrix<T>& operator=(const Matrix<T>& assignedMatrix); // �������� ������������

	int GetRowsCount(); // ������� ��������� ���������� ����� �������

	int GetColumnsCount(); // ������� ��������� ���������� �������� �������

	template <typename T>
	friend	ostream& operator<<(ostream& s, Matrix<T>& outputMatrix); // �������� ������

};


