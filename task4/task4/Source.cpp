#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <Windows.h>

using namespace std;

double Factorial(int n)
{	
	if (n == 1) return (double)n;
	for (int i = n; i >= 1; i--) return (double)i*Factorial(i-1);
}
double Member(int n, double x)
{
	double i;
	i = pow(x, (double)n)/Factorial(n);
	return i;
}
double Rest(int n, double x)
{
	return x*Member(n, x);
}
void MathRound(int accuracy, double x)
{
	x = x*pow(10.0, (double)accuracy);
	if (((x - (int)x) / 0.5) >= 1) x += 1;
	x = x*pow(10.0, - (double)accuracy);
}
double Summ(int accuracy, double x)
{
	int i = 1;
	double summ = 1;
	while (Rest(i, x) > pow(10.0, -(double)accuracy))
	{
		summ += Member(i, x);
		i++;
	}
	MathRound(accuracy,summ);
	return summ;
}
int decimal_places(double x)
{
	int n, X;
	X = x;
	for (n = 0; ; n++)
	{
		if ((int)x == x) break;
		x = 10 * x;
	}
	x = X;
	return n;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << setiosflags(ios::fixed);

	int accuracy;
	double x;
	cout << "Установите значение аргумента x функции exp(x):  ";
	cin >> x;
	cout <<endl<< "Точность вычисления (кол-во знаков после запятой):  ";
	cin >> accuracy;
	cout << "\nexp(" << setprecision(decimal_places(x))<< x << ") = " 
		<< setprecision(accuracy) << Summ(accuracy, x) << "\n" << endl;
	system("pause");
	return 0;
}