#include <iostream>

using namespace std;

int main()
{
	int size;
	cin >> size;

	int* array = new int[size];

	for (int i = 0; i < size; i++)
	{
		int num;
		cin >> num;
		array[i] = num;
	}

	int numToFind, ans;
	cin >> numToFind;
    ans = 0;

	for (int i = 0; i < size; i++)
	{
		if (array[i] == numToFind)
			ans++;
	}
	
	cout << ans;

	return 0;
}