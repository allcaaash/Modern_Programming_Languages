#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <string>
#define N 5

float _matrix[N][N];
int i, j;

// ������� �������
float getMatrixMinValue()
{
	float minValues[N];
	for (i = 0; i < N; i++)
		minValues[i] = *std::min_element(_matrix[i], _matrix[i] + N);
	
	return *std::min_element(minValues, minValues + N);
}

// �������� �������
float getMatrixMaxValue()
{
	float maxValues[N];
	for (i = 0; i < N; i++)
		maxValues[i] = *std::max_element(_matrix[i], _matrix[i] + N);

	return *std::max_element(maxValues, maxValues + N);
}

// �������� ���������������� ����� �������
float getLowMatrixTriangularMaxValue()
{
	float maxValue = _matrix[0][0];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j > i)
				break;
			else
			{
				if (_matrix[i][j] > maxValue)
					maxValue = _matrix[i][j];
			}
		}
	}

	return maxValue;
}

// �������� ����������������� ����� �������
float getUpMatrixTriangularMaxValue()
{
	float maxValue = _matrix[0][N - 1];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j <= i)
				continue;
			else
			{
				if (_matrix[i][j] > maxValue)
					maxValue = _matrix[i][j];
			}
		}
	}

	return maxValue;
}

// ������� ���������������� ����� �������
float getLowMatrixTriangularMinValue()
{
	float minValue = _matrix[0][0];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j > i)
				break;
			else
			{
				if (_matrix[i][j] < minValue)
					minValue = _matrix[i][j];
			}
		}
	}

	return minValue;
}

// ������� ����������������� ����� �������
float getUpMatrixTriangularMinValue()
{
	float minValue = _matrix[0][N - 1];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j <= i)
				continue;
			else
			{
				if (_matrix[i][j] < minValue)
					minValue = _matrix[i][j];
			}
		}
	}

	return minValue;
}

// �������� ������� ��������� �������
float getMatrixMainDiagonalMaxValue()
{
	float mainDiagonalValues[N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j == i)
				mainDiagonalValues[i] = _matrix[i][j];
			else
				continue;
		}
	}

	return *std::max_element(mainDiagonalValues, mainDiagonalValues + N);
}

// ������� ������� ��������� �������
float getMatrixMainDiagonalMinValue()
{
	float mainDiagonalValues[N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j == i)
				mainDiagonalValues[i] = _matrix[i][j];
			else
				continue;
		}
	}

	return *std::min_element(mainDiagonalValues, mainDiagonalValues + N);
}

// �������� �������������� ��������� �������
float getMatrixSecondaryDiagonalMaxValue()
{
	float secondaryDiagonalValues[N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j == N - 1 - i)
				secondaryDiagonalValues[i] = _matrix[i][j];
			else
				continue;
		}
	}

	return *std::max_element(secondaryDiagonalValues, secondaryDiagonalValues + N);
}

// ������� �������������� ��������� �������
float getMatrixSecondaryDiagonalMinValue()
{
	float secondaryDiagonalValues[N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j == N - 1 - i)
				secondaryDiagonalValues[i] = _matrix[i][j];
			else
				continue;
		}
	}

	return *std::min_element(secondaryDiagonalValues, secondaryDiagonalValues + N);
}

// ������������������� ��������� ��������� �������
float getArithmeticMean()
{
	float sum = 0.0;
	int matrixSize = N * N;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			sum += _matrix[i][j];
	}

	return sum / matrixSize;
}

// ������������������� ��������� ��������� ���������������� ����� �������
float getLowMatrixTriangularArithmeticMean()
{
	float sum = 0.0;
	int nums = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j > i)
				break;
			else
			{
				nums++;
				sum += _matrix[i][j];
			}
		}
	}

	return sum / nums;
}

// ������������������� ��������� ��������� ����������������� ����� �������
float getUpMatrixTriangularArithmeticMean()
{
	float sum = 0.0;
	int nums = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j <= i)
				continue;
			else
			{
				nums++;
				sum += _matrix[i][j];
			}
		}
	}

	return sum / nums;
}

// ����� ����� �������
void getMatrixRowsSum()
{
	std::printf("The sum of the rows of the matrix: ");
	for (i = 0; i < N; i++)
	{
		float sum = 0.0;
		for (j = 0; j < N; j++)
			sum += _matrix[i][j];
		if (i < N - 1)
			std::printf("%.1f, ", sum);
		else
			std::printf("%.1f", sum);
	}
	std::printf("\n");
}

// ����� �������� �������
void getMatrixColumnsSum()
{
	std::printf("The sum of the columns of the matrix: ");
	for (i = 0; i < N; i++)
	{
		float sum = 0.0;
		for (j = 0; j < N; j++)
			sum += _matrix[j][i];
		if (i < N - 1)
			std::printf("%.1f, ", sum);
		else
			std::printf("%.1f", sum);
	}
	std::printf("\n");
}

// ����������� �������� ����� �������
void getMatrixRowsMinValue()
{
	std::printf("The minimum value of the rows of the matrix: ");
	for (i = 0; i < N; i++)
	{
		if (i < N - 1)
			std::printf("%.1f, ", *std::min_element(_matrix[i], _matrix[i] + N));
		else
			std::printf("%.1f", *std::min_element(_matrix[i], _matrix[i] + N));
	}
	std::printf("\n");
}

// ����������� �������� �������� �������
void getMatrixColumnsMinValue()
{
	std::printf("The minimum value of the columns of the matrix: ");
	float values[N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			values[j] = _matrix[j][i];

		if (i < N - 1)
			std::printf("%.1f, ", *std::min_element(values, values + N));
		else
			std::printf("%.1f", *std::min_element(values, values + N));
	}
	std::printf("\n");
}

// ������������ �������� ����� �������
void getMatrixRowsMaxValue()
{
	std::printf("The maximum value of the rows of the matrix: ");
	for (i = 0; i < N; i++)
	{
		if (i < N - 1)
			std::printf("%.1f, ", *std::max_element(_matrix[i], _matrix[i] + N));
		else
			std::printf("%.1f", *std::max_element(_matrix[i], _matrix[i] + N));
	}
	std::printf("\n");
}

// ����������� �������� �������� �������
void getMatrixColumnsMaxValue()
{
	std::printf("The maximum value of the columns of the matrix: ");
	float values[N];
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			values[j] = _matrix[j][i];

		if (i < N - 1)
			std::printf("%.1f, ", *std::max_element(values, values + N));
		else
			std::printf("%.1f", *std::max_element(values, values + N));
	}
	std::printf("\n");
}

// �������������������� �������� ����� �������
void getMatrixRowsArithmeticMean()
{
	std::printf("The arithmetic mean of the rows of the matrix: ");
	float res = 0.0;
	for (i = 0; i < N; i++)
	{
		res = 0.0;
		for (j = 0; j < N; j++)
			res += _matrix[i][j];

		if (i < N - 1)
			std::printf("%.1f, ", res / N);
		else
			std::printf("%.1f", res / N);
	}
	std::printf("\n");
}

// �������������������� �������� �������� �������
void getMatrixColumnsArithmeticMean()
{
	std::printf("The arithmetic mean of the columns of the matrix: ");
	float res = 0.0;
	for (i = 0; i < N; i++)
	{
		res = 0.0;
		for (j = 0; j < N; j++)
			res += _matrix[j][i];

		if (i < N - 1)
			std::printf("%.1f, ", res / N);
		else
			std::printf("%.1f", res / N);
	}
	std::printf("\n");
}

// ����� �����- � ����������������� ������ �������
void getUpAndLowTriangulagsSums()
{
	float upperSums = 0.0;
	float lowerSums = 0.0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if (j > i)
				upperSums += _matrix[i][j];
			else
				lowerSums += _matrix[i][j];
		}
	}
	std::printf("The sum of the lower triangular of the matrix: %.1f\n", lowerSums);
	std::printf("The sum of the upper triangular of the matrix: %.1f\n", upperSums);
}

// �������, �������� ������� �� �������� � ���������������������
void getMoreCloseElement()
{
	float mean = getArithmeticMean();
	float minDiff = getMatrixMaxValue();
	float currentDiff = 0.0;
	float result = 0.0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			currentDiff = std::abs(_matrix[i][j] - mean);
			if (minDiff > currentDiff)
			{
				minDiff = currentDiff;
				result = _matrix[i][j];
			}
		}
	}

	std::printf("The element closest in value to the arithmetic mean: %.1f\n", result);
}

// ������������ �������
void main()
{
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) _matrix[i][j] = rand() / 10.;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
			std::cout << std::setw(8) << std::setprecision(5) << _matrix[i][j];
		std::cout << std::endl;
	}

	std::cout << "\n\n";
	std::cout << "Matrix min value: " << getMatrixMinValue() << std::endl;
	std::cout << "Matrix max value: " << getMatrixMaxValue() << std::endl;
	std::cout << "The max value of the lower triangular of the matrix: " << getLowMatrixTriangularMaxValue() << std::endl;
	std::cout << "The max value of the upper triangular of the matrix: " << getUpMatrixTriangularMaxValue() << std::endl;
	std::cout << "The min value of the lower triangular of the matrix: " << getLowMatrixTriangularMinValue() << std::endl;
	std::cout << "The min value of the upper triangular of the matrix: " << getUpMatrixTriangularMinValue() << std::endl;
	std::cout << "The max value of the main diagonal of the matrix: " << getMatrixMainDiagonalMaxValue() << std::endl;
	std::cout << "The min value of the main diagonal of the matrix: " << getMatrixMainDiagonalMinValue() << std::endl;
	std::cout << "The max value of the secondary diagonal of the matrix: " << getMatrixSecondaryDiagonalMaxValue() << std::endl;
	std::cout << "The min value of the secondary diagonal of the matrix: " << getMatrixSecondaryDiagonalMinValue() << std::endl;

	std::cout << "The arithmetic mean of the matrix: " << getArithmeticMean() << std::endl;
	std::cout << "The arithmetic mean of the lower triangular of the matrix: " << getLowMatrixTriangularArithmeticMean() << std::endl;
	std::cout << "The arithmetic mean of the upper triangular of the matrix: " << getUpMatrixTriangularArithmeticMean() << std::endl;

	getMatrixRowsSum();
	getMatrixColumnsSum();
	getMatrixRowsMinValue();
	getMatrixColumnsMinValue();
	getMatrixRowsMaxValue();
	getMatrixColumnsMaxValue();
	getMatrixRowsArithmeticMean();
	getMatrixColumnsArithmeticMean();
	getUpAndLowTriangulagsSums();
	getMoreCloseElement();
}