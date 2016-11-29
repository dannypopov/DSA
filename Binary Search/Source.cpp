#include <iostream>
int binarySearch(int*, int, int);
int main()
{
	int array[5];
	for (int i = 0; i < 5; ++i)
	{
		array[i] = i+1;
	}
	std::cout << binarySearch(array, 3, 5);
	system("PAUSE");
	return 0;
}

int binarySearch(int* sortedArray, int searchedNumber, int size)
{
	int low, high, mid;
	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (sortedArray[mid] == searchedNumber)
		{
			return mid;
		}
		else if (sortedArray[mid] > searchedNumber)
		{
			high = mid - 1;
		}
		else if (sortedArray[mid] < searchedNumber)
		{
			low = mid + 1;
		}
	}
	return -1;
}