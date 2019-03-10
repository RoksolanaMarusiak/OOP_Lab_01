#include<iostream>

using namespace std;

class Time {
private:
	int hour;
	int minute;
	int second;
public:
	Time();
	~Time();

	void SetHour(int hour);
	void SetMinute(int minute);
	void SetSecond(int srcond);
	int GetHour();
	int GetMinute();
	int GetSecond();
};

Time::Time()
{ 
	this->hour = 0;
	this->minute = 0;
	this->second = 0;
}

Time::~Time()
{
}

void Time::SetHour(int hour) 
{
	if (hour < 0 || hour > 23)
	{
		throw "Некоректне значення годин";
	}

	this->hour = hour;
}

void Time::SetMinute(int minute) 
{
	if (minute < 0 || minute > 59)
	{
		throw "Некоректне значення хвилин";
	}

	this->minute = minute;
}

void Time::SetSecond(int second) 
{
	if (second < 0 || second > 59)
	{
		throw "Некоректне значення секунд";
	}

	this->second = second;
}

int Time::GetHour() 
{ 
	return this->hour; 
}

int Time::GetMinute()
{ 
	return this->minute; 
}

int Time::GetSecond() 
{ 
	return this->second; 
}

int main(void)
{
	system("chcp 1251");
	Time* one = new Time;
	int hour = 0, minute = 0, second = 0;
	cout << "=============" << endl;
	cout << "Введення часу:" << endl;
	cout << "Години: ";
	cin >> hour;
	one->SetHour(hour);
	cout << "Хвилини: ";
	cin >> minute;
	one->SetMinute(minute);
	cout << "Секунди: ";
	cin >> second;
	one->SetSecond(second);
	cout << "=============" << endl;
	cout << endl << "Введений час:" << endl;
	cout << endl << "-----------------------------" << endl;
	cout << one->GetHour() << " годин " << one->GetMinute() << " хвилин " << one->GetSecond() << " секунд" << endl;
	cout << "-----------------------------" << endl << endl;
	cout << endl << "---------" << endl;
	cout << one->GetHour() << ":" << one->GetMinute() << ":" << one->GetSecond() << endl;
	cout << "---------" << endl << endl;
	system("pause");
	return 0;
}