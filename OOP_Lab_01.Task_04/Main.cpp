#include <iostream>
#include <string.h>

const int M = 10;

using namespace std;

void fill_nul(char * s, int n); 
long ChysloVStepeni(int ch1, int ch2);

class Integer
{
private:
	char startCh[M];
	int startSys;
public:
	Integer();
	~Integer();

	void SetStSys(int startSys);
	void SetStCh(char *startCh);
	char* Convert10(char *endCh, char *endCh1, int chyslo, int endSystem);
	int Convert();
};

Integer::Integer()
{
	this->startSys = 0;
	this->startCh[11] = { 0 };
}

Integer::~Integer()
{
}

void Integer::SetStSys(int startSys)
{
	this->startSys = startSys;
}

void Integer::SetStCh(char* startCh)
{
	fill_nul(this->startCh, M);
	for (int i = 0; i < M; i++)
	{
		this->startCh[i] = startCh[i];
	}
}

char* Integer::Convert10(char *endCh, char *endCh1, int chyslo, int endSystem)
{
	int k = 0, j = 0, p = 0;
	do
	{
		k = chyslo % endSystem; 	
		chyslo /= endSystem; 
		if (k >= 10)
		{
			endCh[j++] = (char)(k + 'A' - 10); 
		}
		else
		{
			endCh[j++] = (char)(k + '0'); 
		}
	} while (chyslo != 0);
	for (int i = j - 1; i >= 0; i--)
	{
		endCh1[p++] = endCh[i]; 
	}
	return endCh1;
}

int Integer::Convert()
{
	int k, j = 1, decCh = 0, p = 0, endSys = 10;
	do
	{

		k = ChysloVStepeni(startSys, strlen(startCh) - j);

		if (this->startCh[j - 1] - '0' < 10)
		{
			decCh += k * (this->startCh[j - 1] - '0');
		}
		else
		{
			for (int t = 0; t < 26; t++)
			{
				if (this->startCh[j - 1] == 'A' + t)
				{
					decCh += k * (t + 10);
				}
				else if (this->startCh[j - 1] == 'a' + t)
				{
					decCh += k * (t + 10);
				}
			}
		}
		j++;
	} while (k > 1);

	return decCh;
}


int main(void)
{
	Integer *one = new Integer;
	int startSys, endSys, j = 0, p = 0;
	char startCh[M], endCh[M], endCh1[M];
	fill_nul(endCh, M);
	fill_nul(endCh1, M);
	fill_nul(startCh, M);
	cout << "Enter the number:" << endl;
	cin >> startCh;
	cout << "In what system is it? (0-35)" << endl;
	cin >> startSys;
	one->SetStSys(startSys);
	cout << "In what system it should be translated? (0-35)" << endl;
	cin >> endSys;
	if (startSys <= 1 || endSys <= 1 || startSys > 36 || endSys > 36)
	{
		cout << "Incorrect number system" << endl;
		system("pause");
		return 1;
	}
	int chysl = atoi(startCh);
	one->SetStCh(startCh);
	if (startSys == 10)
	{
		one->Convert10(endCh, endCh1, chysl, endSys);
		cout << endl << "Number in " << endSys << " number system:" << endl << endCh1 << endl;
	}
	else
	{
		cout << endl << "Number in decimal number system:" << endl << one->Convert() << endl;
	}
	system("pause");
	return 0;
}

void fill_nul(char * s, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		s[i] = '\0';
	}
}

long ChysloVStepeni(int ch1, int ch2)
{
	if (ch2 == 0)
	{
		return 1;
	}
	long sum = 1;
	for (int i = 1; i <= ch2; i++)
	{
		sum *= ch1;
	}
	return sum;
}