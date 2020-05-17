// KP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//6 вариант

#include <iostream>
#include "Matrix.cpp"
#include "Vector.cpp"
using namespace std;

int main()
{
	
	string answer;
	int n, m, value, i, j, matrixNumberA, matrixNumberB;
	Vector<Matrix<int>> myVector;

	int task;

	do
	{
		cout << "Choose action for matrix:" << endl;
		cout << "0 - Exit;" << endl;
		cout << "1 - Create matrix;" << endl;
		cout << "2 - Fill in the matrix;" << endl;
		cout << "3 - Add matrices;" << endl;
		cout << "4 - Subtract matrices;" << endl;
		cout << "5 - Multiply the matrix by the number;" << endl;
		cout << "6 - Multiply matrices;" << endl;
		cout << "7 - Show matrix." << endl;

		cin >> task; // переменная содержит выбор действия от 1 до 7

		switch (task)
		{
		case 0: break;

		case 1: // Создание матрицы
		{
			cout << "Input count of rows and columns (n,m): ";
			cin >> n >> m;
			cout << "Do you want to fill the matrix with the same value?(Y/n): "; // заполнить матрицу одним значением
			cin >> answer;
			if (answer == "Y" || answer == "y")
			{
				cout << "Input element value: ";
				cin >> value;
				Matrix<int> A(n, m, value);
				myVector.PushBack(A);
			}
			else
			{
				Matrix<int> B(n, m);
				myVector.PushBack(B);
			}
			cout << "Your matrix is in the vector by " << myVector.GetSize() << " index. " << endl;
			cout << myVector[myVector.GetSize() - 1] ;
			break;
		}

		case 2: // Заполнение матрицы
		{
			try
			{
				if (myVector.IsEmpty())
				{
					throw Vector<Matrix<int>>::EmptyException();
				}
				cout << "Input matrix number(number): ";
				cin >> matrixNumberA;
				cout << "Input element index(i,j): ";
				cin >> i >> j;
				cout << "Old element value: " << myVector[matrixNumberA - 1].At(i - 1, j - 1) << endl;
				cout << "Input element new value: ";
				cin >> value;
				myVector[matrixNumberA - 1].At(i - 1, j - 1) = value;
			}
			catch (Vector<Matrix<int>>::EmptyException)
			{
				cout << "Error: Vector doesn't contain matrices." << endl;
				break;
			}
			catch (out_of_range & error)
			{
				cout << "Error: " << error.what() << endl;
				break;
			}
			break;
		}

		case 3: // Суммирование матриц
		{
			try
			{
				if (myVector.IsEmpty())
				{
					throw Vector<Matrix<int>>::EmptyException();
				}
				if (myVector.GetSize() >= 2)
				{
					cout << "Input matrices numbers(numberA, numberB): ";
					cin >> matrixNumberA >> matrixNumberB;
					myVector.PushBack(myVector[matrixNumberA - 1] + myVector[matrixNumberB - 1]);
					cout << "Sum of matrices (A+B) is in the vector by " << myVector.GetSize() << " index. "<<endl;
				}
				else
				{
					throw Matrix<int>::ArgumentsCountException();
				}
			}
			catch (Matrix<int>::DifferentDimensionsException)
			{
				cout << "Error: Matrices of different dimensions." << endl;
				break;
			}
			catch (out_of_range & error)
			{
				cout << error.what() << endl;
				break;
			}
			catch (Matrix<int>::ArgumentsCountException)
			{
				cout << "Error: Not enough arguments for action." << endl;
				break;
			}
			catch (Vector<Matrix<int>>::EmptyException)
			{
				cout << "Error: Vector doesn't contain matrices." << endl;
				break;
			}
			break;
		}

		case 4: // Разность матриц
		{
			try
			{
				if (myVector.IsEmpty())
				{
					throw Vector<Matrix<int>>::EmptyException();
				}
				if (myVector.GetSize() >= 2)
				{
					cout << "Input matrices numbers(numberA, numberB): ";
					cin >> matrixNumberA>> matrixNumberB;
					myVector.PushBack(myVector[matrixNumberA - 1] - myVector[matrixNumberB - 1]);
					cout << "Difference of matrices (A-B) is in the vector by " << myVector.GetSize() << " index. " << endl;
				}
				else
				{
					throw Matrix<int>::ArgumentsCountException();
				}
			}
			catch (Matrix<int>::DifferentDimensionsException)
			{
				cout << "Error: Matrices of different dimensions." << endl;
				break;
			}
			catch (out_of_range & error)
			{
				cout << error.what() << endl;
				break;
			}
			catch (Matrix<int>::ArgumentsCountException)
			{
				cout << "Error: Not enough arguments for action." << endl;
				break;
			}
			catch (Vector<Matrix<int>>::EmptyException)
			{
				cout << "Error: Vector doesn't contain matrices." << endl;
				break;
			}
			break;
		}

		case 5: // Умножение матрицы на число
		{
			try
			{
				if (myVector.IsEmpty())
				{
					throw Vector<Matrix<int>>::EmptyException();
				}
				cout << "Input matrix number(numberA): ";
				cin >> matrixNumberA;
				cout << "Input multiplier number (const): ";
				cin >> n;
				myVector.PushBack(myVector[matrixNumberA - 1] * n);
				cout << "Multiplication of the matrix by the number (A*const) is in the vector by " << myVector.GetSize() << " index. "<<endl;
				
			}
			catch (out_of_range & error)
			{
				cout << error.what() << endl;
				break;
			}
			catch (Vector<Matrix<int>>::EmptyException)
			{
				cout << "Error: Vector doesn't contain matrices." << endl;
				break;
			}
			break;
		}

		case 6: // Перемноение матриц
		{
			try
			{
				if (myVector.IsEmpty())
				{
					throw Vector<Matrix<int>>::EmptyException();
				}
				if (myVector.GetSize() >= 2)
				{
					cout << "Input matrices numbers(numberA, numberB): ";
					cin >> matrixNumberA>> matrixNumberB;
					myVector.PushBack(myVector[matrixNumberA - 1] * myVector[matrixNumberB - 1]);
					cout << "Matrix multiplication (A*B) is in the vector by " << myVector.GetSize() << " index. "<< endl;
				}
				else
				{
					throw Matrix<int>::ArgumentsCountException();
				}
			}
			catch (out_of_range & error)
			{
				cout << error.what() << endl;
				break;
			}
			catch (Matrix<int>::ArgumentsCountException)
			{
				cout << "Error: Not enough arguments for action." << endl;
				break;
			}
			catch (Vector<Matrix<int>>::EmptyException)
			{
				cout << "Error: Vector doesn't contain matrices." << endl;
				break;
			}
			catch (Matrix<int>::DifferentDimensionsException)
			{
				cout << "Error: Matrices of different dimensions." << endl;
				break;
			}
			break;
		}

		case 7: // Вывод матрицы
		{
			try
			{
				if (myVector.IsEmpty())
				{
					throw Vector<Matrix<int>>::EmptyException();
				}
				cout << "Input matrix number(number): ";
				cin >> matrixNumberA;
				cout << myVector[matrixNumberA - 1]; // вывод матрицы
			}
			catch (out_of_range & error)
			{
				cout << error.what() << endl;
				break;
			}
			catch (Vector<Matrix<int>>::EmptyException)
			{
				cout << "Error: Vector doesn't contain matrices." << endl;
				break;
			}
			break;
		}
		}
		cout << endl;
	} while (task != 0);


	return 0;
}