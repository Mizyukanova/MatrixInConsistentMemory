#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Matrix
{
private:

	int rowCount; //количество строк матрицы
	int columnCount; //количество столбцов матрицы
	T* dataPointer; // указатель на область памяти, содержащую последовательность элементов матрицы

public:

	class DifferentDimensionsException {}; // класс исключения, для описания ошибки разных размерностей
	class ArgumentsCountException {}; // класс исключения, для описания ошибки при малом количестве аргументов

	Matrix() // конструктор по-умолчанию
	{
		dataPointer = nullptr;
		rowCount = 0;
		columnCount = 0;
		cout << "Address of created object(1): " << this << endl;
	}

	Matrix(int row, int col) // конструктор с параметрами, где row - количество строк, а col - количество столбцов
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

	Matrix(int row, int col, T value) // конструктор с параметрами, где row - количество строк, col - количество столбцов, а value - значение, которым заполнится вся матрица
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

	Matrix(const Matrix& inputMatrix) // конструктор копирования
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

	~Matrix() // деструктор
	{
		cout << "Address of deleted object: " << this << endl;
		delete[] dataPointer;
	}

	Matrix<T> operator+(const Matrix<T>& secondVector); // оператор суммирования матриц	

	Matrix<T> operator-(const Matrix<T>& secondMatrix); // оператор вычитания матриц

	Matrix<T> operator*(const double constant); // оператор умножения матрицы на число

	Matrix<T> operator*(Matrix<T>& secondMatrix); // оператор перемножения матриц

	T& At(int i, int j); // оператор обращения к значению элемента матрицы по индексу

	Matrix<T>& operator=(const Matrix<T>& assignedMatrix); // оператор присваивания

	int GetRowsCount(); // функция получения количества строк матрицы

	int GetColumnsCount(); // функция получения количества столбцов матрицы

	template <typename T>
	friend	ostream& operator<<(ostream& s, Matrix<T>& outputMatrix); // оператор вывода

};


