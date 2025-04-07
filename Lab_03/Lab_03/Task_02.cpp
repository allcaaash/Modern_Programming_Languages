#include <iostream>
#include "Sort.h"

void Task_02()
{
    int const size = 10;
    int array1[size], array2[size];

    // filling in the array
    std::cout << "The original array1:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        array1[i] = rand() % (100 - 0 + 1) + 0; // 0-100
        std::cout << array1[i] << std::endl;
    }
    std::cout << "The original array2:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        array2[i] = rand() % (100 - 0 + 1) + 0; // 0-100
        std::cout << array2[i] << std::endl;
    }

    Sort::BubbleSort(array1, size);
    std::cout << "Bubble sort result:" << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << array1[i] << std::endl;
    
    Sort::QuickSort(array2, 0, size - 1);
    std::cout << "Quick sort result:" << std::endl;
    for (int i = 0; i < size; i++)
        std::cout << array2[i] << std::endl;
}