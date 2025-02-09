//		x - адрес, на который указывает указатель
//		*x - значение, которое хранится по адресу, на который указывает указатель
//		&x - адрес самого указателя

#define PR(x) printf("x = %p, *x = %d, &x = %p\n", x, *x, &x)
#define PR_CHAR(x) printf("x = %p, *x = %c, &x = %p\n", x, *x, &x)
#define PR_DOUBLE(x) printf("x = %p, *x = %.2f, &x = %p\n", x, *x, &x)
#include <stdio.h>
#include <string>
#include <vector>

void Launch(int* ptr1, int* ptr2)
{
	PR(ptr1);
	ptr1++;
	PR(ptr1);

	PR(ptr2);
	++ptr2;

	// разница между адресами
	printf("ptr2 - ptr1 = %u\n", ptr2 - ptr1);
}

void Launch(char* ptr1, char* ptr2)
{
	PR_CHAR(ptr1);
	ptr1++;
	PR_CHAR(ptr1);

	PR_CHAR(ptr2);
	++ptr2;

	// разница между адресами
	printf("ptr2 - ptr1 = %u\n", ptr2 - ptr1);
}

void Launch(double* ptr1, double* ptr2)
{
	PR_DOUBLE(ptr1);
	ptr1++;
	PR_DOUBLE(ptr1);

	PR_DOUBLE(ptr2);
	++ptr2;

	// разница между адресами
	printf("ptr2 - ptr1 = %u\n", ptr2 - ptr1);
}

void Task_02()
{
	int mas[] = { 100, 200, 300 };
	char ch[] = { 'H', 'W', '!'};
	double db[] = { 3.14, 2.7, -7.89};

	int *ptr1, *ptr2;
	ptr1 = mas;
	ptr2 = &mas[2];
	Launch(ptr1, ptr2);

	char* ch_ptr1, *ch_ptr2;
	ch_ptr1 = ch;
	ch_ptr2 = &ch[2];
	Launch(ch_ptr1, ch_ptr2);

	double* db_ptr1, *db_ptr2;
	db_ptr1 = db;
	db_ptr2 = &db[2];
	Launch(db_ptr1, db_ptr2);
}