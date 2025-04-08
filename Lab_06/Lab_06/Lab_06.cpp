#include <iostream>
#include "CString.h"

int main()
{
    CString s1((char*)"qwerty"), s2, s3(s1), s4;
    s2.input();
    s2 = (char*)"Hello";
    s2.print();
    s4 = s1 + s2 + s3;
    std::cout << "s4 length = " << s4.length() << std::endl;
    if (s1 == s4)
        std::cout << "s1 and s4 is equals";
    else
        if (s1 == s3)
            std::cout << "s1 and s3 is equals";
}