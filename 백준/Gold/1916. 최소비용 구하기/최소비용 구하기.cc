#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

using Edge = pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int N, M;

    cin >> N >> M;

    vector<vector<Edge>> v(N + 1);

    while (M--)
    {
        int s, d, dist;

        cin >> s >> d >> dist;

        v[s].push_back( { dist, d });
    }

    int s, d;
    cin >> s >> d;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<int> distV(N + 1, INT_MAX);
    
    pq.push({0, s});
    distV[s] = 0;

    while (!pq.empty())
    {
        int current_cost = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        if (distV[current_node] < current_cost)
            continue;

        for (const auto& edge : v[current_node])
        {
            int neighbor_cost = edge.first;
            int neighbor_node = edge.second;

            if (distV[neighbor_node] > current_cost + neighbor_cost)
            {
                distV[neighbor_node] = current_cost + neighbor_cost;
                pq.push({ distV[neighbor_node], neighbor_node });
            }
        }
    }

    cout << distV[d];

    return 0;  
}