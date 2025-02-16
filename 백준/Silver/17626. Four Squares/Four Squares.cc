#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>

using namespace std;

vector<int> makeDP(int n)
{
    vector<int> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }

    return dp;
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> dp = makeDP(n);

    cout << dp[n];

    return 0;
}


