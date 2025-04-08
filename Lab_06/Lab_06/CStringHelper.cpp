#include "CStringHelper.h"

int CStringHelper::strlen(char* str)
{
	return (*str) ? CStringHelper::strlen(++str) + 1 : 0;
}

void CStringHelper::strcpy(char* strDestination, const char* strSource)
{
    while (*strSource)
    {
        *strDestination = *strSource;
        strDestination++;
        strSource++;
    }
    *strDestination = '\0';
}

bool CStringHelper::strcmp(char* str1, char* str2)
{
    if (!*str1 && !*str2)
        return true;

    if (*str1 == *str2)
        strcmp(++str1, ++str2);
    else
        return false;
}

void CStringHelper::strcat(char*& str1, char* str2)
{
    int len1 = CStringHelper::strlen(str1);
    int len2 = CStringHelper::strlen(str2);

    char* newstr = new char[len1 + len2 + 1];

    for (int i = 0; i < len1; ++i)
        newstr[i] = str1[i];

    for (int i = 0; i < len2; ++i)
        newstr[len1 + i] = str2[i];

    newstr[len1 + len2] = '\0';

    delete[] str1;
    str1 = newstr;
}