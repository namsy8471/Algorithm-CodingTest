#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<vector<int>> mat(9, vector<int>(9));

	int ret, retRaw, retCal;
	
	ret = 0;
	retRaw = 0;
	retCal = 0;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int num;
			cin >> num;
			mat[i][j] = num;

			if (ret > num) continue;

			ret = num;
			retRaw = i + 1;
			retCal = j + 1;
		}
	}

	cout << ret << endl;
	cout << retRaw << " " << retCal << endl;

	return 0;
}