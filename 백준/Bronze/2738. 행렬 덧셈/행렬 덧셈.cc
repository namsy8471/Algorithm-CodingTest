#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	vector<vector<vector<int>>> mats(2, vector<vector<int>>(n, vector<int>(m)));
	vector<vector<int>> ret(n, vector<int>(m));

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				int num;
				cin >> num;
				mats[i][j][k] = num;
			}
		}
	}



	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			ret[j][k] = mats[0][j][k] + mats[1][j][k];
		}
	}

	for (auto r : ret)
	{
		for (auto c : r)
		{
			cout << c << " ";
		}

		cout << endl;
	}

	return 0;
}