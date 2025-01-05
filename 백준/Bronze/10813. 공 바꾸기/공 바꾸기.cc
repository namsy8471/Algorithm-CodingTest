#include <iostream>

using namespace std;

int main()
{
	int size, times;
	cin >> size >> times;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
		arr[i] = i + 1;
	
	while (times > 0)
	{
		int basket1, basket2;
		cin >> basket1 >> basket2;

		int temp = arr[basket1 - 1];
		arr[basket1 - 1] = arr[basket2 - 1];
		arr[basket2 - 1] = temp;

		times--;
	}

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	delete[] arr;

	return 0;
}