#include <iostream>

using namespace std;

class Stack
{
private:
	int array1[10];
	int first; 
public:
	Stack(); 
	~Stack(); 

	int GetFirst();
	int Add(int d);
	void SetFirst(int d);
	int Take(); 
	void Print();
	int Get(int p);  
	int Amount(); 
	int Max();
	int Min();
};

Stack::Stack() 
{
	this->SetFirst(-1);
}

Stack::~Stack()
{
}

int Stack::GetFirst()
{
	return this->first;
}

int Stack::Add(int d) 
{
	if (this->GetFirst() > 9) return -1;
	this->SetFirst(this->GetFirst() + 1);
	this->array1[this->GetFirst()] = d;
	return 1;
}

void Stack::SetFirst(int d) 
{
	this->first = d;
}

int Stack::Take() 
{
	if (this->GetFirst() == -1) return -1;
	this->SetFirst(this->GetFirst() - 1);
	return this->array1[this->GetFirst() + 1];
}

void Stack::Print() 
{
	cout << "\n---------Print--------\n";
	cout << "First: " << (this->GetFirst()) << "\n";
	cout << "Elements:\n";
	if (this->GetFirst() == -1) cout << "NONE"; else
		for (int i = this->GetFirst(); i >= 0; i--)
			cout << i << "=>" << this->array1[i] << " ";
	cout << "\n";
	cout << "Amount of elements: " << Amount() << endl;
	cout << "Max element: " << Max() << endl;
	cout << "Max element: " << Min() << endl;
	cout << "----------------------\n\n";
}

int Stack::Get(int p) 
{
	if (p > this->GetFirst())
	{
		return -1;
	}

	return this->array1[p];
}

int Stack::Amount() 
{
	int amnt = 0;
	for (int i = this->GetFirst(); i >= 0; i--)
	{
		amnt++;
	}

	return amnt;
}

int Stack::Max()
{
	int max = array1[0];
	for (int i = this->GetFirst(); i >= 0; i--)
	{
		if (max > array1[i])
		{
			max = array1[i];
		}
	}

	return max;
}

int Stack::Min()
{
	int min = array1[0];
	for (int i = this->GetFirst(); i >= 0; i--)
	{
		if (min < array1[i])
		{
			min = array1[i];
		}
	}

	return min;
}

int main(void)
{
	Stack* one = new Stack();
	cout << "Add 9: " << one->Add(9) << endl;
	cout << "Add 7: " << one->Add(7) << endl;
	cout << "Add 0: " << one->Add(0) << endl;
	cout << "Add 7: " << one->Add(7) << endl;
	one->Print();
	cout << "Take: " << one->Take() << endl;
	cout << "Get 2: " << one->Get(2) << endl;
	one->Print();
	system("pause");
	return 0;
}