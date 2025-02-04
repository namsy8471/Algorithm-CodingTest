#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool isRightAngledTriangle(int a, int b, int c)
{
	int max = std::max({a, b, c});

	int min1, min2;

	if (max == a) { min1 = b; min2 = c; }
	else if (max == b) { min1 = a; min2 = c;}
	else { min1 = a; min2 = b;}

	auto pithagorean = [](int max, int min1, int min2)
		{return pow(max, 2) == (pow(min1, 2) + pow(min2, 2)); };

	bool ret = pithagorean(max, min1, min2);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 0 && b == 0 && c == 0) break;

		if (isRightAngledTriangle(a, b, c)) cout << "right" << '\n';
		else cout << "wrong" << '\n';
	}

	return 0;
}