#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int len;
    cin >> len;

    vector<int> v(len);

    for (auto& i : v) cin >> i;

    vector<int> dp(len, 1);

    for (int i = 1; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;  
}