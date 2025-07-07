#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int DFS(std::vector<std::vector<int>>& v)
{

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    std::vector<std::vector<int>> len(v.size(), 
        std::vector<int>(v[0].size(), -1));

    len[0][0] = 1;

    std::queue<std::pair<int, int>> q;
    q.push({ 0 ,0 });

    while (!q.empty())
    {
        std::pair<int,int> currentPos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            std::pair<int, int> newPos = { currentPos.first + dy[i],
            currentPos.second + dx[i] };

            if (newPos.first < 0 || v.size() <= newPos.first) continue;
            if (newPos.second < 0 || v[0].size() <= newPos.second) continue;

            if (v[newPos.first][newPos.second] != 0 &&
                len[newPos.first][newPos.second] == -1)
            {
                q.push(newPos);
                len[newPos.first][newPos.second] = 
                    len[currentPos.first][currentPos.second] + 1;
            }
        }
    }

    return len[v.size() - 1][v[0].size() - 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;

    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n, std::vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        std::string s;
        std::cin >> s;

        for (int j = 0; j < m; j++)
        {
            v[i][j] = s[j] - '0';
        }
    }

    int shortestWay = DFS(v);

    std::cout << shortestWay;

    return 0;  
}