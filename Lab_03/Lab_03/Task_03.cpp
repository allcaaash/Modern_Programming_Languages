#include <iostream>
#include "Sort.h"

bool isEven(int x) {
    return x % 2 == 0;
}

void Task_03()
{
    int mas[] = { 1, 10, 3, 8, 5, 6, 7, 4, 9, 2 };
    int size = sizeof(mas) / sizeof(mas[0]);

    int even[5];
    int odd[5];

    std::cout << "The original array:\n";
    for (int i = 0; i < size; ++i)
        std::cout << mas[i] << " ";
    std::cout << std::endl;

    // Cutting
    int e = 0, o = 0;
    for (int i = 0; i < size; ++i) {
        if (isEven(mas[i]))
        {
            even[e] = mas[i];
            e++;
        }
        else
        {
            odd[o] = mas[i];
            o++;
        }
    }

    Sort::QuickSort(even, 0, 4);
    Sort::QuickSortReverse(odd, 0, 4);

    // Unification
    int ei = 0, oi = 0;
    for (int i = 0; i < size; ++i) {
        if (isEven(mas[i]))
            mas[i] = even[ei++];
        else
            mas[i] = odd[oi++];
    }

    std::cout << "Sort result:\n";
    for (int i = 0; i < size; ++i)
        std::cout << mas[i] << " ";
    std::cout << std::endl;
}