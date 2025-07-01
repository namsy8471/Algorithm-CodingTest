#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;

    cin >> n >> m;
    vector<vector<int>> v(n + 1);

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }

    int min_kevin_bacon = 987654321;
    int result_person = -1;

    for (int i = 1; i <= n; i++)
    {
        int current_total_distance = 0;
        vector<int> dist(n + 1, -1);
        queue<int> q;

        q.push(i);
        dist[i] = 0;
        
        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            current_total_distance += dist[current];

            for (auto neighbor : v[current]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[current] + 1;
                    q.push(neighbor);
                }
            }
        }

        if (current_total_distance < min_kevin_bacon) {
            min_kevin_bacon = current_total_distance;
            result_person = i;
        }
    }

    cout << result_person;

    return 0;  
}