#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	while (true) {
		int a, b, c;

		cin >> a;
		cin >> b;
		cin >> c;

		if (a == 0 && b == 0 && c == 0) break;

		vector<int> v;
		v.push_back(a);
		v.push_back(b);
		v.push_back(c);

		sort(v.begin(), v.end());

		if (v[2] >= v[0] + v[1]) cout << "Invalid" << endl;
		else {
			if (a == b && b == c) cout << "Equilateral" << endl;
			else if (a == b || b == c || a == c) cout << "Isosceles" << endl;
			else cout << "Scalene" << endl;;
		}
	}
	return 0;
}