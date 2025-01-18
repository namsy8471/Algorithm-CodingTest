#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int y, x;

	cin >> y >> x;

	vector<vector<char>> v(y, vector<char>(x));

	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			char c;
			cin >> c;

			v[i][j] = c;
		}
	}

	int limitY = y - 8;
	int limitX = x - 8;

	int ret = 2147483647;

	for (int i = 0; i <= limitY; i++)
	{
		int checkYLim = i + 8;

		for (int j = 0; j <= limitX; j++)
		{
			int checkXLim = j + 8;
			
			char c = 'W';
			int cnt1 = 0;

			for (int checkY = i; checkY < checkYLim; checkY++)
			{
				for (int checkX = j; checkX < checkXLim; checkX++)
				{
					if (c != v[checkY][checkX]) cnt1++;

					if (checkX == checkXLim - 1) continue;

					if (c == 'W') c = 'B';
					else c = 'W';
				}
			}

			c = 'B';
			int cnt2 = 0;

			for (int checkY = i; checkY < checkYLim; checkY++)
			{
				for (int checkX = j; checkX < checkXLim; checkX++)
				{
					if (c != v[checkY][checkX]) cnt2++;

					if (checkX == checkXLim - 1) continue;

					if (c == 'W') c = 'B';
					else c = 'W';
				}
			}

			ret = min(min(cnt1, cnt2), ret);
		}
	}

	cout << ret << endl;

	return 0;
}