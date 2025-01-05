#include <iostream>

constexpr auto STUDENT = 30;

using namespace std;

int main()
{
	int arr[STUDENT];

	for (int i = 0; i < STUDENT; i++)
		arr[i] = 0;
	
	for (int i = 0; i < STUDENT - 2; i++)
	{
		int num;
		cin >> num;
		arr[num - 1] = 1;
	}

	for (int i = 0; i < STUDENT; i++)
	{
		if (arr[i] == 0)
			cout << i + 1 << endl;
	}

	return 0;
}