#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int cnt;

	cin >> cnt;

	vector<pair<int, int>> v;

	for (int i = 0; i < cnt; i++)
	{
		int w, h;
		cin >> w >> h;
		v.push_back(make_pair(w, h));
	}

	vector<int> rankV(v.size(), 1);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++)
		{
			if (i == j) continue;
			if (v[i].first < v[j].first && v[i].second < v[j].second)
				rankV[i]++;
		}
	}

	for (auto i : rankV)
		cout << i << ' ';

	return 0;
}