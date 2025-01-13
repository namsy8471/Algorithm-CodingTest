#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int n, k;
	set<int> s;

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		if(n % i == 0) s.insert(n / i);
	}

	vector<int> v(s.begin(), s.end());

	if (0 <= k - 1 && k - 1 < v.size())
		cout << v[k - 1];
	else cout << 0 << endl;

	return 0;
}