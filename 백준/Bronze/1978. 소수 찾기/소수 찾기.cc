#include <iostream>

using namespace std;

int main()
{
	int cnt, ret;

	ret = 0;
	cin >> cnt;

	while (cnt > 0)
	{
		int n;

		cin >> n;

		if (n >= 3)
		{
			bool isPrime = true;
			for (int i = 2; i < n; i++)
			{
				if (n % i == 0) {
					isPrime = false;
					break;
				}
			}
			if (isPrime) ret++;
		}
		else if (n == 2) ret++;

		cnt--;
	}

	cout << ret << endl;

	return 0;
}