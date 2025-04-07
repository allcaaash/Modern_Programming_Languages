#include <iostream>

void Task_01()
{
   int mas[] = { 2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9 };
   // current min and max index
   int imin, imax;
   int n = sizeof(mas) / sizeof(int);
   int i;
   imin = i = 0;
   imax = i = 0;

   system("CLS");

   for (i = 0; i < n; i++)
       std::cout << mas[i] << ' ';
   std::cout << std::endl;

   for (i = 0; i < n - 1; i++) // find min and max
   {
       imin = i;
       for (int j = i + 1; j < n; j++)
           if (mas[j] < mas[imin]) imin = j;
       int t = mas[i];
       mas[i] = mas[imin];
       mas[imin] = t;
   }
   for (i = 0; i < n; i++) // screen output
       std::cout << mas[i] << ' ';
   std::cout << std::endl;
}