#define _USE_MATH_DEFINES

#include<iostream>
#include<math.h>

using namespace std;

class Circle
{
private:
	double radius;
	int x;
	int y;
	int z;
public:
	Circle();
	~Circle();

	void SetRadius(double cradius);
	double GetRadius();
	double Square();
	double Length();
	void SetX(int X);
	void SetY(int Y);
	void SetZ(int Z);
	int GetX();
	int GetY();
	int GetZ();
};

Circle::Circle()
{
	this->radius = 0;
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Circle::~Circle()
{
}

void Circle::SetRadius(double cradius)
{
	if (cradius <= 0)
	{
		throw "Incorrect radius";
	}

	this->radius = cradius;

}

double Circle::GetRadius()
{
	return this->radius;
}

double Circle::Square() {
	return (this->radius * this->radius * M_PI);
}

double Circle::Length()
{
	return (2 * this->radius * M_PI);
}

void Circle::SetX(int X)
{
	this->x = X;
}

void Circle::SetY(int Y)
{
	this->y = Y;
}

void Circle::SetZ(int Z)
{
	this->z = Z;
}

int Circle::GetX()
{
	return this->x;
}

int Circle::GetY()
{
	return this->y;
}

int Circle::GetZ()
{
	return this->z;
}


int main(void)
{
	int X, Y, Z;
	double cradius;
	Circle *one = new Circle;
	cout << "Coordinates of the center:" << endl;
	cout << "x = ";
	cin >> X;
	cout << "y = ";
	cin >> Y;
	cout << "z = ";
	cin >> Z;
	cout << "Radius:" << endl;
	cin >> cradius;
	one->SetX(X);
	one->SetY(Y);
	one->SetZ(Z);
	one->SetRadius(cradius);
	cout << endl << "------Print------" << endl;
	cout << "Coordinates of the center:" << endl;
	cout << "O(" << one->GetX() << ";" << one->GetY() << ";" << one->GetZ() << ")" << endl;
	cout << "Radius:" << endl << one->GetRadius() << endl;
	cout << "Length" << endl << one->Length() << endl;
	cout << "Square" << endl << one->Square() << endl;
	cout << "------------------" << endl << endl;
	system("pause");
	return 0;
}