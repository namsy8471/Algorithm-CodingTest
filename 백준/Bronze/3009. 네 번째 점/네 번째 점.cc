#include <iostream>
#include <vector>

using namespace std;

pair<int, int> MakeRectangle(vector<pair<int, int>> v)
{
	pair<int, int> ret;

	if (v[0].first == v[1].first)
		ret.first = v[2].first;
	else if (v[0].first == v[2].first)
		ret.first = v[1].first;
	else ret.first = v[0].first;

	if (v[0].second == v[1].second)
		ret.second = v[2].second;
	else if (v[0].second == v[2].second)
		ret.second = v[1].second;
	else ret.second = v[0].second;

	return ret;
}

int main()
{
	vector<pair<int, int>> v;

	int cnt = 3;
	while (cnt > 0)
	{
		int x, y;
		cin >> x >> y;

		v.push_back(make_pair(x, y));
		cnt--;
	}

	pair<int, int> ret = MakeRectangle(v);

	cout << ret.first << " " << ret.second << endl;

	return 0;
}