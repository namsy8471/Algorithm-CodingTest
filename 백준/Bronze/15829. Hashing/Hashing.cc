#include <iostream>
#include <cmath>

constexpr auto r = 31;
constexpr auto M = 1234567891;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int len;

	cin >> len;

	unsigned long long ret = 0;

	for (int i = 0; i < len; i++)
	{
		char c;
		cin >> c;

		ret += (c - 'a' + 1) * pow(r, i);
	}

	if (ret / M != 0) ret %= M;

	cout << ret;

	return 0;
}