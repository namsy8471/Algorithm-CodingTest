#include <iostream>

using namespace std;

int getZeroFromFactorial(int n)
{
	int ret = 0;

	while (n >= 5)
	{
		ret += n / 5;
		n /= 5;
	}

	return ret;
}

int main()
{
	int n;

	cin >> n;

	cout << getZeroFromFactorial(n);

	return 0;
}