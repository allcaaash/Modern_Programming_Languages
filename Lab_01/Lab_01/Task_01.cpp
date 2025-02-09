#include <iostream>

void Task_01()
{
	int i, k;
	int power(int, int);

	std::cout << "Enter the base of the degree: ";
	int num;
	std::cin >> num;
	for (i = 0; i < 10; i++)
	{
		k = power(num, i);
		std::cout << "i = " << i << ", k = " << k << std::endl;
	}
}

int power(int x, int n)
{
	int i, p = 1;
	for (i = 1; i <= n; i++)
		p *= x;
	return p;
}