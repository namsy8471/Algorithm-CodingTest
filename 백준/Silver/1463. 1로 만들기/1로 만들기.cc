#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<int> Func() {
    
    vector<int> dp(1000000 + 1, INT_MAX);

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    
    for (int i = 4; i <= 1000000; i++)
    {
        dp[i] = dp[i - 1] + 1;
        
        if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
    }

    return dp;
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v = Func();

    cout << v[n];

    return 0;
}
