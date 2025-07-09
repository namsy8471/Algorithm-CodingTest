#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp(const vector<vector<int>>& v)
{
    vector<vector<int>> ret(v.size(), vector<int>(3));

    ret[0][0] = v[0][0];
    ret[0][1] = v[0][1];
    ret[0][2] = v[0][2];

    for (int i = 1; i < v.size(); i++)
    {
        ret[i][0] = v[i][0] + min(ret[i - 1][1], ret[i - 1][2]);
        ret[i][1] = v[i][1] + min(ret[i - 1][0], ret[i - 1][2]);
        ret[i][2] = v[i][2] + min(ret[i - 1][0], ret[i - 1][1]);
    }

    return min({ ret[v.size() - 1][0], ret[v.size() - 1][1], ret[v.size() - 1][2] });
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int cnt;

    cin >> cnt;

    vector<vector<int>> v(cnt, vector<int>(3, 0));

    for (int i = 0; i < cnt; i++)
    {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    cout << dp(v);

    return 0;  
}