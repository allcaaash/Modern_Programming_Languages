#include <iostream>
#include <fstream>
#include "Task_4.h"

void Task_4()
{
    std::ofstream outFile("book.txt");

    if (outFile.is_open()) {
        outFile << "1\nPage one\nText\n\f";
        outFile << "2\nPage two\nText\n\f";
        outFile.close();
        std::cout << "File written successfully!" << std::endl;
    }
    else {
        std::cerr << "Failed to open file!" << std::endl;
    }

    char book[10] = "book.txt";
    PageNumberTransfer(book);
}

void PageNumberTransfer(char* fileName)
{
    FILE* in;
    if (fopen_s(&in, fileName, "r"))
        return;
    char page[10000];
    char ch;
    int i = 0;
    while ((ch = getc(in)) != EOF)
    {
        page[i] = ch;

        if (ch == '\f')
        {
            char pageNum[5];
            bool isFirstLine = true;
            for (int j = 0; page[j] != '\f'; j++)
            {
                if (isFirstLine)
                    pageNum[j] = page[j];
                else
                    std::cout << page[j];

                if (page[j] == '\n' && isFirstLine)
                {
                    isFirstLine = false;
                    pageNum[j] = '\0';
                }
            }
            std::cout << pageNum;
            std::cout << '\f';

            for (int j = 0; j != i; j++)
                page[j] = '\0';
            i = -1;
            std::cout << '\n';
        }

        i++;
    }
}