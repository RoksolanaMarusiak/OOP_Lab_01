#include <iostream>   
#include <stdlib.h>         
#include <stdio.h>  

using namespace std;

class Matrix
{
private:
	int Rows;
	int Cols;
	int ** IntData;

public:
	Matrix(int Row = 1, int Col = 1);
	~Matrix(void);
	int GetAt(int Row, int Col);
	void SetAt(int Row, int Col, int Data);
	void Display();
	int Max();
	int Min();
	int Sum();
	void Fill();
};

Matrix::Matrix(int Row, int Col)
{
	Rows = Row;
	Cols = Col;
	IntData = new int *[Rows];
	for (int j = 0; j < Rows; j++)
	{
		IntData[j] = new int[Cols];
		for (int i = 0; i < Cols; i++)
		{
			IntData[j][i] = 0;
		}
	}
};

Matrix::~Matrix()
{
	for (int j = 0; j < Rows; j++)
	{
		delete IntData[j];
	}
	delete[] IntData;
};

int Matrix::GetAt(int Row, int Col)
{
	if (Row < 0 || Row > Rows)
		Row = 0;
	if (Col < 0 || Col > Cols)
		Col = 0;
	return IntData[Row][Col];
};

void Matrix::SetAt(int Row, int Col, int Data)
{
	if (Row < 0 || Row > Rows)
		Row = 0;
	if (Col < 0 || Col > Cols)
		Col = 0;
	IntData[Row][Col] = Data;
}

int Matrix::Sum()
{
	int Sum = 0;
	for (int i = 0; i < this->Cols; ++i)
	{

		for (int j = 0; j < this->Rows; ++j)
		{
			Sum += IntData[i][j];

		}
	}

	return Sum;
}

int Matrix::Max()
{
	int max = IntData[0][0];

	for (int i = 0; i < this->Cols; ++i)
	{
		for (int j = 0; j < this->Rows; ++j)
		{
			if (IntData[i][j] > max)
			{
				max = IntData[i][j];
			}
		}
	}

	return max;
}

int Matrix::Min()
{
	int min = IntData[0][0];

	for (int i = 0; i < this->Cols; ++i)
	{
		for (int j = 0; j < this->Rows; ++j)
		{
			if (IntData[i][j] < min)
			{
				min = IntData[i][j];
			}
		}
	}

	return min;
}

void Matrix::Fill()
{
	for (int j = 0; j < Rows; j++)
	{
		for (int i = 0; i < Cols; i++)
		{
			cout << "\nMatrix[" << i << "][" << j << "] = ";
			cin >> IntData[j][i];
		}
	}
}

void Matrix::Display()
{
	cout << "\n Matrix \n" << endl;
	for (int j = 0; j < Rows; j++)
	{
		cout << "  ";
		for (int i = 0; i < Cols; i++)
		{
			cout << IntData[j][i] << " ";
		}
		cout << endl;
	}
	cout << endl << "Sum of elements: " << Sum() << endl;
	cout << "Max element: " << Max() << endl;
	cout << "Min element: " << Min() << endl << endl;
}

int main(void)
{
	int Row, Col;
	cout << "\nRow: ";
	cin >> Row;
	cout << "\nCol: ";
	cin >> Col;

	Matrix one(Row, Col);
	one.Fill();
	one.Display();
	system("pause");
	return 0;
}

