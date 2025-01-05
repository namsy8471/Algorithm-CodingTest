#include <iostream>

using namespace std;

int main()
{
	int size, times;
	cin >> size >> times;

	int* arr = new int[size]();

	while (times > 0)
	{
		int start, end, ballNum;
		cin >> start >> end >> ballNum;

		for (int i = start; i <= end; i++)
		{
			arr[i - 1] = ballNum;
		}

		times--;
	}

	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";

	delete[] arr;

	return 0;
}