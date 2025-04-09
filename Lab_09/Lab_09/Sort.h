template <class T>
void Sort(T array[], size_t size)
{
	T temp;
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
}