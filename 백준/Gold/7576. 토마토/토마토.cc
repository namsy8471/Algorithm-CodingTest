#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int searchByBFS(const vector<vector<int>>& v)
{
    int r = v.size();
    int c = v[0].size();

    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    vector<vector<int>> timeToTake(r, vector<int>(c, -1));
    queue<pair<int,int>> q;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] == 1) {
                q.push({ i, j });
                timeToTake[i][j] = 1;
            }
        }
    }

    while (!q.empty())
    {
        pair<int,int> pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int newY = dy[i] + pos.first;
            int newX = dx[i] + pos.second;

            if (newY < 0 || r <= newY) continue;
            if (newX < 0 || c <= newX) continue;

            if (v[newY][newX] == 0 &&
                timeToTake[newY][newX] == -1)
            {
                q.push({ newY, newX });
                timeToTake[newY][newX] =
                    timeToTake[pos.first][pos.second] + 1;
            }
        }
    }

    int max = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (v[i][j] == 0 && timeToTake[i][j] == -1) {
                return -1;
            }

            max = std::max(timeToTake[i][j], max);
        }
    }
    
    return max - 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int col, row;

    std::cin >> col >> row;


    vector<vector<int>> v(row, vector<int>(col));

    for (auto& r : v)
        for (auto& c : r) cin >> c;

    int ret = searchByBFS(v);

    cout << ret;

    return 0;  
}