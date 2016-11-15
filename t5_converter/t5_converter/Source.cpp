#include <iostream>
#include <sstream>
#include <stdio.h>
#include <locale>
#include  <stdlib.h>
#include <string>


using namespace std;

template <typename T>
std::string toString(T val)
{
	std::ostringstream oss;
	oss << val;
	return oss.str();
}

template<typename T>
T fromString(const std::string& s)
{
	std::istringstream iss(s);
	T res;
	iss >> res;
	return res;
}

void format(string number, char z)
{
	for (int i = 0; i < number.length(); i++)
	{
		if ((int(number[i]) > int('a') || int(number[i]) <= int('z')) && 
			(int(number[i]) > int('0') || int(number[i]) <= int('9')) && 
			(int(number[i]) > int('A') || int(number[i]) <= int('Z')))
		{
			if (int(number[i]) >= int('a') && int(number[i]) <= int('z')) number[i] = char(int(number[i]) - 32);
		}
		else
		{
			z = 3;
			break;
		}
	}
}
bool SysCheck(int X, string number)
{	
	bool Y = true;
	for(int i = 0; i < number.length(); i++)
	{
		if (X <= 10 && int(char(number[i])) - int('0') >= X)
		{
			Y = false;
			break;
		}
		else
		{
			if (int(char(number[i]) - int('A') + 10) >= X)
			{
				Y = false;
				break;
			}
		}
	}
	
	return Y;
}
string ConvertFromXtoY(int X, int Y, string number)
{
	int a = 0, b;
	if(X != 10)
	{
		for(int i = 0; i < number.length(); i++)
		{
			if (int(number[i]) >= int('0') && int(number[i]) <= int('9')) b = int('0');
			else b = int('A') - 10;
			a += (int(number[i])-b)*int(pow(X, (number.length() - i - 1)));
		}
		number = toString(a);
	}
	else a = fromString<int>(number);
	if(Y != 10)
	{
		number.clear();
		for(;;)
		{	
			if (fmod(a, Y) >= 10) number += char(int('A') + fmod(a, Y) - 10);
			else number += int(fmod(a,Y));
			if (a / Y == 0) break;
			a = a / Y;
		}
		number.rend();
	}

	return number;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string number;
	int X, Y, z;
	cout << "Нажмите 1, если хотите перевести число в другую систему счисления."<<endl;
	cout << "Нажмите 2, если хотите проверить принадлежность к той или иной системе счисления."<< endl;
	cin >> z;
	
	return 0;
}
