#include <iostream>
#include "Vector.h"

template <typename T>
void Vector<T>::SetDefaultValues() // ������� ��������� �������� ��-���������
{
	T defaultValue = T();
	for (int i = 0; i < size; i++)
	{
		*(dataPointer + i) = defaultValue;
	}
}

template <typename T>
T& Vector<T>::operator[](int i) // �������� ��������� � �������� �������� ������� �� �������
{
	if (i < 0 || i > size - 1)
	{
		throw std::out_of_range("index out of range"); // ������ � ���, ��� � ����� try �������� �������������� ������� � ������
	}

	return *(dataPointer + i);
}

template <typename T>
int Vector<T>::GetSize() // ������� ��������� ������� �������
{
	return size;
}

template <typename T>
bool Vector<T>::IsEmpty() // ������� �������� �� ������� �������
{
	if (size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& assignedVector) // �������� ������������
{
	if (dataPointer != 0)
	{
		delete[] dataPointer;
	}
	size = assignedVector.size;
	capacity = assignedVector.capacity;
	dataPointer = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		*(dataPointer + i) = *(assignedVector.dataPointer + i);
	}

	return *this;
}


template <typename T>
void Vector<T>::PushBack(T newElement) // ������� ��� ���������� ������ �������� � ����� ������� 
{
	if (size < capacity)
	{
		dataPointer[size] = newElement;
		size++;
	}
	else if (capacity == 0) // ������� �� ������ ������
	{
		capacity = 2;
		size = 1;
		dataPointer = new T[capacity];
		dataPointer[size - 1] = newElement;
	}
	else // ������� �� ������������� ������ ��� �������
	{
		capacity *= 2;
		T* dataPointerNew = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			*(dataPointerNew + i) = *(dataPointer + i);
		}
		dataPointerNew[size] = newElement;
		size++;
		delete[] dataPointer;
		dataPointer = dataPointerNew;
	}
}

template <typename T>
void Vector<T>::Insert(T newElement, int place)
{
	if (place < 0 || place > size) // �������� �� ����� �� �������� �������
	{
		throw std::out_of_range("index out of range");
		return;
	}
	if (size < capacity)
	{
		T* dataPointerNew = new T[capacity];
		for (int i = 0; i < place; i++)
		{
			*(dataPointerNew + i) = *(dataPointer + i);
		}
		dataPointerNew[place] = newElement;
		for (int i = place + 1; i <= size; i++)
		{
			*(dataPointerNew + i) = *(dataPointer + i - 1);
		}
		delete[] dataPointer;
		dataPointer = dataPointerNew;
		size++;
	}
	else if (capacity == 0) // ������� �� ������ ������
	{
		capacity = 2;
		size = 1;
		dataPointer = new T[capacity];
		dataPointer[place] = newElement;
	}
	else // ������� �� ������������� ������ ��� �������
	{
		capacity = 2 * size;
		T* dataPointerNew = new T[capacity];
		for (int i = 0; i < place; i++)
		{
			*(dataPointerNew + i) = *(dataPointer + i);
		}
		dataPointerNew[place] = newElement;
		for (int i = place + 1; i <= size; i++)
		{
			*(dataPointerNew + i) = *(dataPointer + i - 1);
		}
		delete[] dataPointer;
		dataPointer = dataPointerNew;
		size++;
	}
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
	Iterator it(dataPointer); //������������� ��������� ���������� �� ������ �������
	return it;
}

template <typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
	Iterator it(dataPointer + size); //������������� ��������� ���������� �� ����� �������
	return it;
}

