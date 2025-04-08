#include "CString.h"

#include <iostream>
#include "CStringHelper.h"

CString::CString()
{
	str = new char[101];
}

CString::CString(int size)
{
	str = new char[size];
}

CString::CString(char* string)
{
	str = new char[CStringHelper::strlen(string) + 1];
	CStringHelper::strcpy(str, string);
}

CString::CString(const CString& s)
{
	str = new char[CStringHelper::strlen(s.str) + 1];
	CStringHelper::strcpy(str, s.str);
}

CString::~CString()
{
	delete[] str;
}

CString& CString::operator=(const CString& s)
{
	CStringHelper::strcpy(str, s.str);
	return *this;
}

CString& CString::operator+(const CString& s)
{
	CStringHelper::strcat(str, s.str);
	return *this;
}

bool CString::operator==(const CString& s)
{
	if (CStringHelper::strcmp(str, s.str))
		return 1;
	else
		return 0;
}

int CString::length()
{
	return CStringHelper::strlen(str);
}

void CString::print()
{
	std::cout << str << std::endl;
}

void CString::input()
{
	std::cin >> str;
}