#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(int x, int y, vector<vector<char>>& v, vector<vector<bool>>& b, int& cnt)
{
    int dx[] = { 1, 0, -1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    if (v[y][x] == 'X' || b[y][x]) return;
    b[y][x] = true;
    
    if(v[y][x] == 'P') cnt++;
    
    for (int i = 0; i < 4; i++)
    {
        if (0 <= x + dx[i] && x + dx[i] < v[0].size()
            && 0 <= y + dy[i] && y + dy[i] < v.size())

            dfs(x + dx[i], y + dy[i], v, b, cnt);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<char>> v(n, vector<char>(m, ' '));
    vector<vector<bool>> b(n, vector<bool>(m, false));

    int startX, startY;

    startX = 0;
    startY = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'I') {
                startX = j;
                startY = i;
            }
        }
    }

    int cnt = 0;

    dfs(startX, startY, v, b, cnt);

    if (cnt == 0) cout << "TT";
    else cout << cnt;

    return 0;  
}