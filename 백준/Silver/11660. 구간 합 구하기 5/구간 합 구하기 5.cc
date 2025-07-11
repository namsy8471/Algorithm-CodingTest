#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int N, cnt;

    cin >> N >> cnt;

    vector<vector<int>> v(N + 1, vector<int>(N + 1));
    vector<vector<int>> memo(N + 1, vector<int>(N + 1));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }

    
    for (int i = 1; i < N + 1; i++)
    {
        for (int j = 1; j < N + 1; j++)
        {
            memo[i][j] = v[i - 1][j - 1]
                + memo[i - 1][j] + memo[i][j - 1]
                - memo[i - 1][j - 1];
        }
    }
    

    while (cnt--)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        int ret = memo[x2][y2] - memo[x1 - 1][y2]
            - memo[x2][y1 - 1] + memo[x1 - 1][y1 - 1];

        cout << ret;
        cout << '\n';
    }
    

    return 0;  
}