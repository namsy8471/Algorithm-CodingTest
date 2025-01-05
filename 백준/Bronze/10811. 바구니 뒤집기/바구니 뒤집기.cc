#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int size, times;
	cin >> size >> times;

	vector<int> v(size, 0);

	for (int i = 0; i < size; i++)
		v[i] = i + 1;

	while (times > 0)
	{
		int start, end;
		cin >> start >> end;

		reverse(v.begin() + start - 1, v.begin() + end);

		times--;
	}
	
	for (auto i : v)
		cout << i << " ";

	return 0;
}