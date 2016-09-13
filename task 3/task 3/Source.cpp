#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int summF(int n) 
{
	int s = 0, a = 0, b = 1, c;
	for (int i = 1; i <= n+1; i++)
	{
		s += a;
		c = b;
		b += a;
		a = c;
	}
	return s;
}

int main()
{  
	int n;
	std::cin >> n;
	std::cout << summF(n);
	return 0;
}