#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recursion(vector<vector<int>>& v, vector<vector<int>>& memo, int depth, int idx)
{
    if (v.size() - 1 == depth)
        return v[depth][idx];

    if (memo[depth][idx] != -1)
        return memo[depth][idx];

    int result = max(v[depth][idx] + recursion(v, memo, depth + 1, idx)
        , v[depth][idx] + recursion(v, memo, depth + 1, idx + 1));

    memo[depth][idx] = result;

    return result;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int h;

    cin >> h;

    vector<vector<int>> v(h);
    vector<vector<int>> memo(h, vector<int>(h, -1));

    for (int i = 0; i < h; i++)
    {
        for (int j = h - i; j <= h; j++)
        {
            int num;
            cin >> num;
            v[i].push_back(num);
        }
    }

    cout << recursion(v, memo, 0, 0);

    return 0;  
}