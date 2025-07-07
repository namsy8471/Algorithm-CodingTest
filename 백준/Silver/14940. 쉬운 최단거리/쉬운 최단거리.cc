#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<std::vector<int>> BFS(const std::vector<std::vector<int>>& v)
{

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    std::vector<std::vector<int>> len(v.size(), 
        std::vector<int>(v[0].size(), -1));

    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 2)
            {
                len[i][j] = 0;
                q.push({ i, j });
                break;
            }
        }
    }

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

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == 0)
            {
                len[i][j] = 0;
            }
        }
    }

    return len;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;

    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n, std::vector<int>(m, -1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> v[i][j];
        }
    }

    std::vector<std::vector<int>> shortestWayList = BFS(v);

    for (auto& v : shortestWayList)
    {
        for (auto& i : v)
            std::cout << i << " ";
        std::cout << '\n';
    }

    return 0;  
}