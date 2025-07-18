#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;

    cin >> N;

    vector<vector<int>> v(N + 1, vector<int>(N + 1, 1));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<vector<int>>> memo(3, vector<vector<int>>(N + 1, vector<int>(N + 1, 0)));

    memo[0][1][2] = 1;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 3; j <= N; j++)
        {
            if (v[i][j] == 1) continue;

            memo[0][i][j] = memo[0][i][j - 1] + memo[2][i][j - 1];
            memo[1][i][j] = memo[1][i - 1][j] + memo[2][i - 1][j];

            if (v[i - 1][j] == 0 && v[i][j - 1] == 0)
                memo[2][i][j] = memo[0][i - 1][j - 1] + memo[1][i - 1][j - 1]
                + memo[2][i - 1][j - 1];
        }
    }

    cout << memo[0][N][N] + memo[1][N][N] + memo[2][N][N];
    
    return 0;  
}