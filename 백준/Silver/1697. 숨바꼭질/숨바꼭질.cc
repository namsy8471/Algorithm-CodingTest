#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;

    cin >> n >> k;
    
    vector<int> dist(100001, -1);

    queue<int> q;

    q.push(n);
    dist[n] = 0;

    while (!q.empty())
    {
        int curPos = q.front();
        q.pop();

        if (curPos == k) break;

        if (curPos - 1 >= 0 && dist[curPos - 1] == -1)
        {
            dist[curPos - 1] = dist[curPos] + 1;
            q.push(curPos - 1);
        }
        if (curPos + 1 <= 100000 && dist[curPos + 1] == -1)
        {
            dist[curPos + 1] = dist[curPos] + 1;
            q.push(curPos + 1);
        }
        if (curPos * 2 <= 100000 && dist[curPos * 2] == -1)
        {
            dist[curPos * 2] = dist[curPos] + 1;
            q.push(curPos * 2);
        }
    }

    cout << dist[k];

    return 0;  
}