#include <iostream>  
#include <vector>  

using namespace std;  

void DFS(vector<vector<bool>>& visited, vector<vector<int>>& v, int x, int y)
{
    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, 1, 0, -1 };

    for (int j = 0; j < 4; j++)
    {
        if (y + dy[j] >= 0 && y + dy[j] < v.size()
            && x + dx[j] >= 0 && x + dx[j] < v[0].size()
            && v[y + dy[j]][x + dx[j]] == 1
            && visited[y + dy[j]][x + dx[j]] == false)
        {
            visited[y + dy[j]][x + dx[j]] = true;
            DFS(visited, v, x + dx[j], y + dy[j]);
        }
    }
}

int CheckLeastEarthworm(int width, int height, int lettuce)  
{  
    vector<vector<int>> v(height, vector<int>(width, 0));
    vector<vector<bool>> visited(height, vector<bool>(width, false));

    while (lettuce--)
    {
        int x, y;
        cin >> x >> y;
        v[y][x] = 1;
    }

    int ret = 0;
    
    for (int i = 0; i < height; i++) // y 좌표 (행)
    {
        for (int j = 0; j < width; j++) // x 좌표 (열)
        {
            if (v[i][j] == 1 && visited[i][j] == false)
            {
                ret++;
                visited[i][j] = true;
                DFS(visited, v, j, i);
            }
        }
    }

    return ret;
}

int main() {  

    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  

    int cnt;  

    cin >> cnt;  

    while (cnt--)  
    {  
        int width, height, lettuce;  

        cin >> width >> height >> lettuce;  

        cout << CheckLeastEarthworm(width, height, lettuce) << '\n';
    }  

    return 0;  
}