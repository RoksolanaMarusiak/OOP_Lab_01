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
		throw "���������� �������� �����";
	}

	this->hour = hour;
}

void Time::SetMinute(int minute) 
{
	if (minute < 0 || minute > 59)
	{
		throw "���������� �������� ������";
	}

	this->minute = minute;
}

void Time::SetSecond(int second) 
{
	if (second < 0 || second > 59)
	{
		throw "���������� �������� ������";
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
	cout << "�������� ����:" << endl;
	cout << "������: ";
	cin >> hour;
	one->SetHour(hour);
	cout << "�������: ";
	cin >> minute;
	one->SetMinute(minute);
	cout << "�������: ";
	cin >> second;
	one->SetSecond(second);
	cout << "=============" << endl;
	cout << endl << "�������� ���:" << endl;
	cout << endl << "-----------------------------" << endl;
	cout << one->GetHour() << " ����� " << one->GetMinute() << " ������ " << one->GetSecond() << " ������" << endl;
	cout << "-----------------------------" << endl << endl;
	cout << endl << "---------" << endl;
	cout << one->GetHour() << ":" << one->GetMinute() << ":" << one->GetSecond() << endl;
	cout << "---------" << endl << endl;
	system("pause");
	return 0;
}