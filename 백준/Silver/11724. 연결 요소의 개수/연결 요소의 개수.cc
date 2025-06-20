#include <iostream>
#include <vector>

using namespace std;

void DFS(int start,const vector<vector<int>>& v, vector<bool>& isVisited)
{
    isVisited[start] = true;

    for (auto i : v[start])
    {
        if (isVisited[i]) continue;

        DFS(i, v, isVisited);
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num, cnt;
    cin >> num >> cnt;

    vector<vector<int>> v(num + 1);
    vector<bool> isVisited(num + 1, false);

    while (cnt--)
    {
        int n1, n2;
        cin >> n1 >> n2;

        v[n1].push_back(n2);
        v[n2].push_back(n1);
    }

    int ret = 0;

    for (int i = 1; i < num + 1; i++)
    {
        if (isVisited[i]) continue;
        
        DFS(i, v, isVisited);
        ret++;
    }

    cout << ret;

    return 0;
}