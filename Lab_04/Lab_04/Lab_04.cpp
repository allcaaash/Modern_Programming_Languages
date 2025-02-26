#include <iostream>
#include <string.h>

int main()
{
    char str1[] = "qwerty", str2[] = "1234567890";
    int strlen1(char*);
    int strlen2(char*);
    int strlen3(char*);
    void strcpy(char*, char*);
    void strcmp(char*, char*);
    void strcat(char*, char*);
    
    std::cout << "Lenght_1: str1 = " << strlen1(str1) << ", str2 = " << strlen1(str2) << std::endl;
    std::cout << "Lenght_2: str1 = " << strlen2(str1) << ", str2 = " << strlen2(str2) << std::endl;
    std::cout << "Lenght_3: str1 = " << strlen3(str1) << ", str2 = " << strlen3(str2) << std::endl;

    std::cout << "Before copy: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    strcpy(str1, str2);
    std::cout << "After copy: str1 = " << str1 << ", str2 = " << str2 << std::endl;

    std::cout << "Before compare: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    strcmp(str1, str2);    

    std::cout << "Before concatenation: str1 = " << str1 << ", str2 = " << str2 << std::endl;
    strcat(str1, str2);
}

int strlen1(char* str)
{
    return (*str) ? strlen1(++str) + 1 : 0;
}

int strlen2(char* str)
{
    int result = 0;
    while (*str)
    {
        str++;
        result++;
    }
    return result;
}

int strlen3(char* str)
{
    char* start = str;
    while (*str)
        str++;
    return str - start;
}

void strcpy(char* strDestination, char* strSource)
{
    while (*strDestination)
    {
        if (*strSource)
        {
            *strDestination = *strSource;
            strDestination++;
            strSource++;
        }
        else
        {
            *strDestination = '\0';
            strDestination++;
        }
    }
}

void strcmp(char* str1, char* str2)
{
    if (!*str1 && !*str2)
    {
        std::cout << "Compare result: TRUE" << std::endl;
        return;
    }

    if (*str1 == *str2)
    {
        strcmp(++str1, ++str2);
    }
    else
    {
        std::cout << "Compare result: FALSE" << std::endl;
        return;
    }
}

void strcat(char* str1, char* str2)
{
    char newstr[80];
    int i = 0;
    while (*str1)
    {
        newstr[i] = *str1;
        str1++;
        i++;
    }
    while (*str2)
    {
        newstr[i] = *str2;
        str2++;
        i++;
    }

    newstr[i] = '\0';
    std::cout << "Concatenation result: " << newstr << std::endl;
}
