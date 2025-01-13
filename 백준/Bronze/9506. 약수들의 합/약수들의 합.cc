#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	while (true)
	{
		set<int> s;
		int num;

		cin >> num;

		if (num == -1) break;

		for (int i = 1; i < num; i++)
			if (num % i == 0) s.insert(i);

		vector<int> v(s.begin(), s.end());

		int sum = 0;
		for (auto i : v) sum += i;

		if (num != sum)
			cout << num << " is NOT perfect." << endl;

		else {
			cout << num << " = ";
			for (auto i : v)
			{
				if (i != v[v.size() - 1])
					cout << i << " + ";
				else
					cout << i << endl;
			}
		}
	}

	return 0;
}