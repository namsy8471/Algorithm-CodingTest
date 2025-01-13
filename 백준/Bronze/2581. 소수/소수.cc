#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int m, n;

	cin >> m;
	cin >> n;

	vector<int> v;

	for (int i = m; i <= n; i++)
	{
		bool isPrime = true;

		if (i == 1) continue;
		else if (i == 2) v.push_back(i);
		else {
			for (int j = 2; j <= sqrt(i); j++)
			{
				if (i % j == 0) {
					isPrime = false;
					break;
				}
			}

			if (isPrime) v.push_back(i);
		}
	}

	if (v.empty()) cout << -1 << endl; 
	else {
		int sum = 0;
		for (auto i : v) sum += i;

		cout << sum << endl;
		cout << v[0] << endl;
	}

	return 0;
}