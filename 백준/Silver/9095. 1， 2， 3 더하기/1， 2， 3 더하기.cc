#include <iostream>
#include <vector>

using namespace std;

vector<int> MakeDP(int n)
{
    vector<int> dp(n + 1);

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
    }

    return dp;
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    vector<int> dp = MakeDP(10);

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}


