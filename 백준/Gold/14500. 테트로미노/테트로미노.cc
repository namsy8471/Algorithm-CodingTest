#include <iostream>  
#include <vector>

using namespace std;

void CheckTetrominoAndUpdateMax(int y, int x, vector<vector<int>>& v, int& max)
{
    vector<vector<pair<int, int>>> shapes;

    int dx[] = { 1, 1, -1, -1 , 1, 1, -1, -1 };
    int dy[] = { 1, -1, 1, -1 , 1, -1, 1, -1 };

    vector<pair<int, int>> shape1 = { make_pair(0, 0),
    make_pair(0, 1), make_pair(0, 2), make_pair(0, 3) };

    vector<pair<int, int>> shape2 = { make_pair(0, 0),
    make_pair(1, 0), make_pair(2, 0), make_pair(2, 1) };

    vector<pair<int, int>> shape3 = { make_pair(0, 0),
    make_pair(1, 0), make_pair(1, 1), make_pair(2, 1) };

    vector<pair<int, int>> shape4 = { make_pair(0, 0),
    make_pair(0, 1), make_pair(1, 0), make_pair(1, 1) };

    vector<pair<int, int>> shape5 = { make_pair(0, 0),
    make_pair(0, 1), make_pair(0, 2), make_pair(1, 1) };

    shapes.push_back(shape1);
    shapes.push_back(shape2);
    shapes.push_back(shape3);
    shapes.push_back(shape4);
    shapes.push_back(shape5);

    for (int cnt = 0; cnt < shapes.size(); cnt++)
    {
        int sum = 0;
        bool reverse = false;

        for (int j = 0; j < 8; j++)
        {
            reverse = 4 <= j;

            if (!reverse) {
                for (int i = 0; i < shapes[cnt].size(); i++)
                {
                    int ny = shapes[cnt][i].first * dy[j] + y;
                    int nx = shapes[cnt][i].second * dx[j] + x;

                    if (0 > ny || ny >= v.size() ||
                        0 > nx || nx >= v[0].size())
                    {
                        sum = 0;
                        break;
                    }

                    sum += v[ny][nx];
                }
            }
            else {
                for (int i = 0; i < shapes[cnt].size(); i++)
                {
                    int ny = shapes[cnt][i].second * dy[j] + y;
                    int nx = shapes[cnt][i].first * dx[j] + x;

                    if (0 > ny || ny >= v.size() ||
                        0 > nx || nx >= v[0].size())
                    {
                        sum = 0;
                        break;
                    }

                    sum += v[ny][nx];
                }
            }

            if (max < sum) max = sum;
            sum = 0;
        }
    }
}

int main() {  

    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  

    int height, width;

    cin >> height >> width;

    vector<vector<int>> v(height, vector<int>(width, 0));

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cin >> v[y][x];
        }
    }

    int max = 0;

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            CheckTetrominoAndUpdateMax(y, x, v, max);
        }
    }

    cout << max;

    return 0;  
}



