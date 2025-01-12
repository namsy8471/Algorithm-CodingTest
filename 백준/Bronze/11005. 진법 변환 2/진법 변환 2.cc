#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char ExchangeNum(const int i)
{
	char ret = '0';
	
	if (0 <= i && i <= 9) ret += i;
	else ret = 'A' + (i - 10);

	return ret;
}

int main()
{
	string ret;

	int n = 0;
	int b = 0;
	
	cin >> n >> b;

	int divide;
	int left = n;

	while (left > 0)
	{
		divide = left % b;
		left /= b;

		ret += ExchangeNum(divide);
	}

	reverse(ret.begin(), ret.end());

	cout << ret;

	return 0;
}