#include <iostream>
#include <vector>

using namespace std;

vector<int> makeDP(int n)
{
    vector<int> dp(n + 1);

    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    for (int i = 3; i < n + 1; i++)
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
         
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


