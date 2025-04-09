#include "Money.h"

Money::Money()
{
	dollars = 0;
	cents = 0;
}

Money::Money(long d, int c)
{
	dollars = d;
	cents = c;
}

int Money::operator >(const Money& amt) const
{
	return
		(dollars > amt.dollars) ||
		((dollars == amt.dollars) && (cents == amt.cents));
}

std::ostream& operator <<(std::ostream& os, Money& amt)
{
	os << "$" << amt.dollars << '.' << amt.cents;
	return os;
}