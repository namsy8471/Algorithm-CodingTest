#include <iostream>
#include <string>

using namespace std;

bool Equal(int a, int b, int c, int x, int y) {

	return ((a * x) + (b * y)) == c;
}

int main()
{
	int a, b, c, d, e, f;

	cin >> a >> b >> c >> d >> e >> f;

	int x = -1000, y = -1000;

	for (int i = -999; i <= 999; i++)
	{
		for (int j = -999; j <= 999; j++)
		{
			if (!Equal(a, b, c, i, j)) continue;
			if (!Equal(d, e, f, i, j)) continue;

			x = i;
			y = j;

			break;
		}

		if (x == i) break;
	}

	cout << x << " " << y;

	return 0;
}