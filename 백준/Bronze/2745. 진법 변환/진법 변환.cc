#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int ExchangeNum(const char c)
{
	int ret = 0;

	if ('0' <= c && c <= '9')
		ret = c - '0';
	else if ('A' <= c && c <= 'Z')
		ret = c - 'A' + 10;

	return ret;
}

int main()
{
	int ret = 0;

	string n;
	int b;

	cin >> n >> b;

	for (int i = 0; i < n.length(); i++)
	{
		ret += ExchangeNum(n[i]) * pow(b, n.length() - i - 1);
	}

	cout << ret;

	return 0;
}