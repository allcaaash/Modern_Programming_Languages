#include "Tasks_1_2_3.h"
#include <iostream>
#include <fstream>

void Tasks_1_2_3()
{
    char ch, name[50], substring[100];
    FILE* in;
    int notEmptyCount = 0, emptyCount = 0;
    printf("Enter the file name to the wathing: ");
    if (!scanf_s("%s", name, sizeof(name)) || fopen_s(&in, name, "r"))
        printf("\nFile \"%s\" is not be opened\n", name);
    else
    {
        while ((ch = getc(in)) != EOF)
        {
            putchar(ch);
            CountChar(ch, notEmptyCount, emptyCount);
        }
        fclose(in);

        printf("\nNot empty chars in the file: %d\nEmpty chars in the file: %d\n", notEmptyCount, emptyCount);

        printf("Enter the substring to search in the file: ");
        scanf_s("%s", substring, sizeof(substring));
        FindSubstring(name, substring);
    }
}

void CountChar(char& ch, int& notEmptyCount, int& emptyCount)
{
    if (isspace(ch))
        emptyCount++;
    else
        notEmptyCount++;
}

void FindSubstring(char* fileName, char* substring)
{
    FILE* in;
    if (fopen_s(&in, fileName, "r"))
        return;
    char line[1000];
    while (fgets(line, sizeof(line), in))
    {
        if (strstr(line, substring))
            std::cout << line;
    }

    fclose(in);
}