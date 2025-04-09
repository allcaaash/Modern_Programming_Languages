#pragma once
#include <iostream>

class Money
{
	long dollars;
	int cents;
public:
	Money();
	Money(long d, int c);
	int operator >(const Money&) const;
	friend std::ostream& operator <<(std::ostream&, Money&);
};

