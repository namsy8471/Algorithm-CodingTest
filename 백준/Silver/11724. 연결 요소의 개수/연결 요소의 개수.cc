#include <iostream>  
#include <queue>

using namespace std;

int DFS(int start,const vector<vector<int>>& v, vector<bool>& isVisited)
{
    if (isVisited[start]) return 0;

    isVisited[start] = true;

    for (int i = 1; i < v.size(); i++)
    {
        if (v[start][i] == 1 && !isVisited[i]) {
            DFS(i, v, isVisited);
        }
    }

    return 1;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, cnt;
    cin >> num >> cnt;

    vector<vector<int>> v(num + 1, vector<int>(num + 1, 0));
    vector<bool> isVisited(num + 1, false);

    while (cnt--)
    {
        int n1, n2;
        cin >> n1 >> n2;

        v[n1][n2] = 1;
        v[n2][n1] = 1;
    }

    int ret = 0;

    for (int i = 1; i < num + 1; i++)
    {
        ret += DFS(i, v, isVisited);
    }

    cout << ret;

    return 0;
}