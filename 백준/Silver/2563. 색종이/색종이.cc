#include <iostream>
#include <map>
using namespace std;

int main()
{
	int cnt;

	cin >> cnt;

	map<pair<int, int>, int> m;

	while (cnt > 0)
	{
		int x, y;

		cin >> x >> y;

		for (int i = x; i < x + 10; i++)
		{
			for (int j = y; j < y + 10; j++)
			{
				m[make_pair(i, j)] = 1;
			}
		}

		cnt--;
	}

	int ret = 0;

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (m[make_pair(i, j)] == 1) ret++;
		}
	}

	cout << ret << endl;

	return 0;
}