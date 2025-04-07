#include <iostream>
#include "Sort.h"

void Task_05()
{
    int mas[] = { 1, 10, 3, 8, 5, 6, 7, 4, 9, 2 };
    int size = sizeof(mas) / sizeof(mas[0]);

    std::cout << "The original array:\n";
    for (int i = 0; i < size; ++i)
        std::cout << mas[i] << " ";
    std::cout << std::endl;

    // sort from 0 to 4
    Sort::QuickSortReverse(mas, 0, 4);

    std::cout << "Sort result:\n";
    for (int i = 0; i < size; ++i)
        std::cout << mas[i] << " ";
    std::cout << std::endl;
}