#include <iostream>

constexpr auto MAX = 15;

using namespace std;

int dp[MAX][MAX];

void countPeople()
{
	for (int i = 0; i < MAX; i++) {
		dp[0][i] = i;
		dp[i][1] = 1;
	}

	for (int f = 1; f < MAX; f++)
	{
		for (int n = 1; n < MAX; n++)
			dp[f][n] = dp[f][n - 1] + dp[f - 1][n];
	}
}

int main()
{
	int cnt;

	cin >> cnt;

	countPeople();

	for (int i = 0; i < cnt; i++)
	{
		int floor, roomNum;

		cin >> floor >> roomNum;

		cout << dp[floor][roomNum] << '\n';
	}

	return 0;
}