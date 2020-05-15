// KP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template <typename T>
class Matrix
{
private:
	int n; //количество строк матрицы
	int m; //количество столбцов матрицы
	T* dataPointer; // указатель на область памяти, содержащую последовательность элементов матрицы
	
	//void SetDefaultValues();

public:
	Matrix() // конструктор по-умолчанию
	{
		dataPointer = nullptr;
		size = 0;
		capacity = 0;
	}
	Matrix(int n) // конструктор с параметром, где n - количество элементов в векторе
	{
		size = n;
		capacity = 2 * n;
		dataPointer = new T[capacity];
		//SetDefaultValues();
	}
	Matrix(Matrix& inputVector) // конструктор копирования
	{
		size = inputVector.size;
		capacity = inputVector.capacity;
		dataPointer = new T[capacity];

		for (int i = 0; i < size; i++)
		{
			*(dataPointer + i) = *(inputVector.dataPointer + i);
		}
	}
	~Matrix() // деструктор
	{
		delete[] dataPointer;
	}

	Matrix& operator=(const Matrix& assignedVector); // оператор копирующего присваивания

	T& operator[](int i); // обращение к i-му элементу

	int GetSize(); // получение количества элементов в векторе

	bool IsEmpty(); // проверкa на пустоту вектора

	void PushBack(T newElement); // добавление в конец нового элемента

	void Insert(T newElement, int place); // вставка элемента в определенную позицию вектора

	class Iterator
	{
	private:
		T* pointer; //указатель на элемент вектора
	public:
		Iterator() // конструктор по-умолчанию
		{
			pointer = 0;
		}
		Iterator(T* inputPointer) // конструктор с параметром
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

int main()
{
    std::cout << "Hello World!\n";
	
}