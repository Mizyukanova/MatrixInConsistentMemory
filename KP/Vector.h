#pragma once

#include <iostream>

template <typename T>
class Vector
{
private:

	T* dataPointer; // ��������� �� ������� ������, ���������� ������� �������
	int size; //���������� ��������� � �������
	int capacity; //����������� ������� ��� ���������� ���������� ������
	void SetDefaultValues();

public:

	class EmptyException {};

	Vector() // ����������� ��-���������
	{
		dataPointer = nullptr;
		size = 0;
		capacity = 0;
	}

	Vector(int n) // ����������� � ����������, ��� n - ���������� ��������� � �������
	{
		size = n;
		capacity = 2 * n;
		dataPointer = new T[capacity];
		//SetDefaultValues();
	}

	Vector(Vector& inputVector) // ����������� �����������
	{
		size = inputVector.size;
		capacity = inputVector.capacity;
		dataPointer = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			*(dataPointer + i) = *(inputVector.dataPointer + i);
		}
	}

	~Vector() // ����������
	{
		delete[] dataPointer;
	}

	Vector& operator=(const Vector& assignedVector); // �������� ����������� ������������
	
	T& operator[](int i); // ��������� � i-�� ��������

	int GetSize(); // ��������� ���������� ��������� � �������

	bool IsEmpty(); // �������a �� ������� �������

	void PushBack(T newElement); // ���������� � ����� ������ ��������

	void Insert(T newElement, int place); // ������� �������� � ������������ ������� �������

	class Iterator
	{
	private:

		T* pointer; //��������� �� ������� �������
	
	public:

		Iterator() // ����������� ��-���������
		{
			pointer = 0;
		}

		Iterator(T* inputPointer) // ����������� � ����������
		{
			pointer = inputPointer;
		}

		Iterator& operator++() 
		{
			pointer++;
			return *this;
		}

		T& operator*() const
		{
			return *pointer;
		}

		bool operator!=(Iterator comparisonIterator)
		{
			if (pointer != comparisonIterator.pointer)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	};

	Iterator begin();

	Iterator end();

};


