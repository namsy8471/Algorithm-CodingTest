#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<string> v;

	for (int i = 0; i < 5; i++)
	{
		string s;
		cin >> s;

		v.push_back(s);
	}

	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 5; i++)
		{
			if (v[i].length() > j) cout << v[i][j];
		}
	}

	return 0;
}