#include "Sort.h"

void Sort::BubbleSort(int array[], const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void Sort::QuickSort(int array[], int left, int right)
{
    int i = left, j = right;
    int pivot = array[(left + right) / 2]; // support element

    while (i <= j)
    {
        while (array[i] < pivot) i++;
        while (array[j] > pivot) j--;

        if (i <= j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) QuickSort(array, left, j);
    if (i < right) QuickSort(array, i, right);
}

void Sort::QuickSortReverse(int array[], int left, int right)
{
    int i = left, j = right;
    int pivot = array[(left + right) / 2]; // support element

    while (i <= j)
    {
        while (array[i] > pivot) i++;
        while (array[j] < pivot) j--;

        if (i <= j)
        {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j) QuickSortReverse(array, left, j);
    if (i < right) QuickSortReverse(array, i, right);
}