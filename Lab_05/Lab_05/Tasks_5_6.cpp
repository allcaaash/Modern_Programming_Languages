#include "Tasks_5_6.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

void Tasks_5_6(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Использование: " << argv[0] << " <входной файл> <выходной файл> <ключ>\n";
        return;
    }

    try 
    {
        encryptFile(argv[1], argv[2], argv[3]);

        std::cout << "Файл успешно зашифрован.\n";
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Ошибка: " << e.what() << "\n";
        return;
    }
}
void Tasks_5_6()
{

    try 
    {
        encryptFile("in.txt", "out.txt", "qwerty");
        std::cout << "Completed.\n";
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Error: " << e.what() << "\n";
        return;
    }
}

void encryptFile(char* inputFilename, char* outputFilename, char* key)
{
    char ch;
    int i = 0;
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;
    fopen_s(&inputFile, inputFilename, "r");
    fopen_s(&outputFile, outputFilename, "w");
    if (inputFile == NULL || outputFile == NULL)
    {
        std::printf("Can not open a files for read or whrite\n");
        return;
    }

    while (!std::feof(inputFile))
    {
        if (key[i] == '\0')
            i = 0;
        ch = getc(inputFile);
        ch ^= key[i];
        fputc(ch, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
}

void encryptFile(std::string inputFilename, std::string outputFilename, std::string key)
{
    char ch;
    int i = 0;
    FILE* inputFile = NULL;
    FILE* outputFile = NULL;
    fopen_s(&inputFile, inputFilename.c_str(), "r");
    fopen_s(&outputFile, outputFilename.c_str(), "w");
    if (inputFile == NULL || outputFile == NULL)
    {
        std::printf("Can not open a files for read or whrite\n");
        return;
    }

    while ((ch = getc(inputFile)) != EOF)
    {
        if (key[i] == '\0')
            i = 0;
        ch ^= key[i];
        fputc(ch, outputFile);
        i++;
    }
    fclose(inputFile);
    fclose(outputFile);
}