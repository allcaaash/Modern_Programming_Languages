#include <iostream>
#include "Money.h"
#include "Sort.h"

void Task_01()
{
	Money mas[] = 
	{	Money(19, 10),
		Money(99, 99),
		Money(99, 95),
		Money(19, 95)
	};

	Sort(mas, sizeof(mas) / sizeof(mas[0]));
	for (int i = 0; i < sizeof(mas) / sizeof(mas[0]); i++)
		std::cout << "mas[" << i << "] = " << mas[i] << std::endl;
}