#include <iostream>
#include <algorithm>

template <class T>
class Tstack {
protected:
	int numItem;
	int maxSize;
	T* item;
public:
	Tstack(size_t size = 10)
	{
		numItem = 0;
		maxSize = size;
		item = new T[size];
	}

	~Tstack()
	{
		delete[] item;
	}

	void push(T t)
	{
		if (numItem < maxSize)
			item[numItem++] = t;
		else
			throw std::overflow_error("Stack overflow");
	}

	T pop()
	{
		if (numItem > 0)
			return item[--numItem];
		throw std::underflow_error("Pop from empty stack");
	}

	bool empty() const {
		return numItem == 0;
	}
};

void Task_03()
{
	int input[] = {1, 5, 3};
	int size = sizeof(input) / sizeof(input[0]);

	Tstack<int> stack(size);
	int* output = new int[size];
	int outIndex = 0;

	for (int i = 0; i < size; ++i) {
		int current = input[i];

		int* temp = new int[size];
		int tempCount = 0;

		while (!stack.empty()) {
			int top = stack.pop();
			if (top < current) {
				temp[tempCount++] = top;
			}
			else {
				output[outIndex++] = top;
			}
		}

		for (int j = tempCount - 1; j >= 0; --j)
			stack.push(temp[j]);

		stack.push(current);

		delete[] temp;
	}

	while (!stack.empty()) {
		output[outIndex++] = stack.pop();
	}

	for (int i = 0; i < outIndex; ++i)
		std::cout << output[i] << " ";
	std::cout << std::endl;

	delete[] output;
}