#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetMaxFromDP(vector<vector<int>>& v, vector<vector<int>>& memo)
{
    memo[0][0] = v[0][0];
    memo[1][0] = v[1][0];
    memo[0][1] = v[0][1] + memo[1][0];
    memo[1][1] = v[1][1] + memo[0][0];

    for (int x = 2; x < v[0].size(); x++)
    {
        memo[0][x] = v[0][x] + max({ memo[0][x - 2], memo[1][x - 1], memo[1][x - 2] });
        memo[1][x] = v[1][x] + max({ memo[1][x - 2], memo[0][x - 1], memo[0][x - 2] });
    }

    auto find_max = [&memo]() -> int
        {
            return max(*max_element(memo[0].begin(), memo[0].end()),
                *max_element(memo[1].begin(), memo[1].end()));
        };

    return find_max();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int cnt;

    cin >> cnt;

    while (cnt--)
    {
        int num;

        cin >> num;

        vector<vector<int>> v(2, vector<int>(num, 0));
        vector<vector<int>> memo(2, vector<int>(num, 0));

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < num; j++)
                cin >> v[i][j];
        }

        cout << GetMaxFromDP(v, memo);
        cout << '\n';
    }
    

    return 0;  
}