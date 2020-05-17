#include "Matrix.h"

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& secondMatrix) // �������� ������������ ������
{
	if (rowCount == secondMatrix.rowCount && columnCount == secondMatrix.columnCount)
	{
		Matrix<T> resultMatrix(rowCount, columnCount);
		for (int i = 0; i < rowCount * columnCount; i++)
		{
			*(resultMatrix.dataPointer + i) = *(this->dataPointer + i) + *(secondMatrix.dataPointer + i);
		}

		return resultMatrix;
	}
	else
	{
		throw DifferentDimensionsException();
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& secondMatrix) // �������� ��������� ������
{
	Matrix<T> resultMatrix(rowCount, columnCount);
	if (rowCount == secondMatrix.rowCount && columnCount == secondMatrix.columnCount)
	{
		for (int i = 0; i < rowCount * columnCount; i++)
		{
			*(resultMatrix.dataPointer + i) = *(this->dataPointer + i) - *(secondMatrix.dataPointer + i);
		}

		return resultMatrix;
	}
	else
	{
		throw DifferentDimensionsException();
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const double constant) // �������� ��������� ������� �� �����
{
	Matrix<T> resultMatrix(rowCount, columnCount);
	for (int i = 0; i < rowCount * columnCount; i++)
	{
		*(resultMatrix.dataPointer + i) = *(this->dataPointer + i) * constant;
	}

	return resultMatrix;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T>& secondMatrix) // �������� ������������ ������
{
	
	if (columnCount == secondMatrix.rowCount)
	{
		Matrix<T> resultMatrix(this->rowCount, secondMatrix.columnCount);
		for (int i = 0; i < this->rowCount; i++)
		{
			for (int j = 0; j < secondMatrix.columnCount; j++)
			{
				for (int k = 0; k < this->columnCount; k++)
				{
					resultMatrix.At(i, j) += this->At(i, k) * secondMatrix.At(k, j);
					//*(resultMatrix.dataPointer + i * this.column + j) += *(this->dataPointer + k + i) * *(secondMatrix.dataPointer + k + j);
				}
			}
		}

		return resultMatrix;
	}
	else
	{
		throw DifferentDimensionsException();
	}
}

template <typename T>
T& Matrix<T>::At(int i, int j) // �������� ��������� � �������� �������� ������� �� �������
{
	if (i < 0 || j < 0 || i > rowCount - 1 || j > columnCount - 1)
	{
		throw std::out_of_range("Error: Index out of range."); // ������ � ���, ��� � ����� try �������� �������������� ������� � ������
	}

	return *(dataPointer + i * columnCount + j);
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& assignedMatrix) // �������� ������������
{
	if (rowCount != assignedMatrix.rowCount || columnCount != assignedMatrix.columnCount)
	{
		delete[] dataPointer;
	}
	rowCount = assignedMatrix.rowCount;
	columnCount = assignedMatrix.columnCount;
	dataPointer = new T[rowCount * columnCount];

	for (int i = 0; i < rowCount * columnCount; i++)
	{
		*(dataPointer + i) = *(assignedMatrix.dataPointer + i);
	}

	return *this;
}

template <typename T>
int Matrix<T>::GetRowsCount() // ������� ��������� ���������� ����� �������
{
	return rowCount;
}

template <typename T>
int Matrix<T>::GetColumnsCount() // ������� ��������� ���������� �������� �������
{
	return columnCount;
}

template <typename T>
ostream& operator<<(ostream& s, Matrix<T>& outputMatrix) // �������� ������
{
	for (int i = 0; i < outputMatrix.GetRowsCount(); i++)
	{
		for (int j = 0; j < outputMatrix.GetColumnsCount(); j++)
		{
			cout << outputMatrix.At(i, j) << " ";
		}
		cout << endl;
	}
	return s;
}
