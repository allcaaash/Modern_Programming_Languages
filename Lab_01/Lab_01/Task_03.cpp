#include <iostream>

void Task_03()
{
	int a = 2, b = 5;
	void Exchange_01(int, int);
	void Exchange_02(int*, int*);
	void Exchange_03(int&, int&);

	std::cout << "Before exchange: a = " << a << ", b = " << b << std::endl;
	Exchange_01(a, b);
	std::cout << "After exchange: a = " << a << ", b = " << b << std::endl;
	Exchange_02(&a, &b);
	std::cout << "After exchange #2: a = " << a << ", b = " << b << std::endl;
	Exchange_03(a, b);
	std::cout << "After exchange #3: a = " << a << ", b = " << b << std::endl;
}

void Exchange_01(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Exchange_02(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Exchange_03(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}