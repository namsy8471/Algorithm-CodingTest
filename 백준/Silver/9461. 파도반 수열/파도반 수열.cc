#include <iostream>
#include <vector>

using namespace std;

vector<long long> GetDP(int n)
{
    vector<long long> dp(n + 1);
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= n; i++)
    {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    return dp;
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    vector<long long> dp = GetDP(100);

    for (int i = 0; i < t; i++)
    {
        int cnt;
        cin >> cnt;

        cout << dp[cnt] << '\n';
    }

    return 0;
}


