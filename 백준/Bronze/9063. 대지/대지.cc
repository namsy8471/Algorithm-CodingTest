#include <iostream>
#include <cmath>

using namespace std;

int GetRectArea(int cnt)
{
	int minX = 10001, maxX = -10001;
	int minY = 10001, maxY = -10001;

	while (cnt > 0)
	{
		int x, y;

		cin >> x >> y;

		minX = min(x, minX);
		maxX = max(x, maxX);
		minY = min(y, minY);
		maxY = max(y, maxY);

		cnt--;
	}

	return (maxX - minX) * (maxY - minY);
}

int main()
{
	int cnt;

	cin >> cnt;

	int ret = GetRectArea(cnt);
	cout << ret << endl;

	return 0;
}