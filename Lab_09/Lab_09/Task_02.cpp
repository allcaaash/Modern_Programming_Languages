#include <iostream>
#include <string.h>

template <class T>
T getmax(T t1, T t2)
{
	return t1 > t2 ? t1 : t2;
}

char* getmax(char* s1, char* s2)
{
	return strcmp(s1, s2) ? s1 : s2;
}

template <class T>
T getmax(T t[], size_t size)
{
	T retval = t[0];
	for (int i = 0; i < size; i++)
		if (t[i] > retval) retval = t[i];
	return retval;
}

void First()
{
	int i1 = 3, i2 = 5;
	int mas[] = { 3, 9, 5, 8 };
	std::cout << "max int = " << getmax(i1, i2) << std::endl;
	std::cout << "max int = ";
	std::cout << getmax(mas, sizeof(mas) / sizeof(mas[0])) << std::endl;
}



void Second()
{
	int i1 = 3, i2 = 5;
	const char* s1 = "String 1";
	const char* s2 = "String 2";
	std::cout << "max int = " << getmax(i1, i2) << std::endl;
	std::cout << "max str = " << getmax(s1, s2) << std::endl;
}

void Task_02()
{
	First();
	Second();
}