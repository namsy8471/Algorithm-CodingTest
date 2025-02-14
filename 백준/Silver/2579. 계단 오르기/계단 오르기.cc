#include <iostream>
#include <vector>

using namespace std;

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector<int> v(n + 1);
    vector<int> dp(n + 1);

    if(n >= 1) cin >> v[1];
    if(n >= 2) cin >> v[2];

    if (n == 1) { cout << v[1]; return 0; }
    
    dp[1] += v[1];
    dp[2] += v[1] + v[2];

    for (int i = 3; i <= n; i++)
    {
        cin >> v[i];

        dp[i] = max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]);
    }

    cout << dp[n];

    return 0;
}
