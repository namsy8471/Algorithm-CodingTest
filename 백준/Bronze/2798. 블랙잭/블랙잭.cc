#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	vector<int> v;

	while (n > 0)
	{
		int i;

		cin >> i;

		v.push_back(i);

		n--;
	}

	sort(v.begin(), v.end());
	
	vector<int> ret;

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = i + 1; j < v.size(); j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				ret.push_back(v[i] + v[j] + v[k]);
			}
		}
	}

	sort(ret.begin(), ret.end(), greater<int>());

	for (int i = 0; i < ret.size(); i++) {
		if (ret[i] > m) continue;

		cout << ret[i] << endl;
		break;
	}

	return 0;
}