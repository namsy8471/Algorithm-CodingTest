#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

using Edge = pair<int, int>;

vector<int> dijkstra(int start, int dest, const vector<vector<Edge>>& graph)
{
    vector<int> dist(dest + 1, std::numeric_limits<int>::max());
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    pq.push({ 0, start });
    dist[start] = 0;

    while (!pq.empty())
    {
        int currentNode = pq.top().second;
        int currentDist = pq.top().first;

        pq.pop();

        if (dist[currentNode] < currentDist) continue;

        for (const auto& e : graph[currentNode])
        {
            int nextNode = e.second;
            int nextDist = e.first;

            if (dist[nextNode] > dist[currentNode] + nextDist)
            {
                dist[nextNode] = dist[currentNode] + nextDist;
                pq.push({ dist[nextNode], nextNode });
            }
        }
    }

    return dist;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, E;

    cin >> N >> E;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < E; i++)
    {
        int from, to, dist;
        cin >> from >> to >> dist;
        graph[from].emplace_back(dist, to);
        graph[to].emplace_back(dist, from);
    }

    int node1, node2;

    cin >> node1 >> node2;

    vector<int> distFromStart = dijkstra(1, N, graph);
    vector<int> distFromNode1 = dijkstra(node1, N, graph);
    vector<int> distFromNode2 = dijkstra(node2, N, graph);

    long long path1 = -1, path2 = -1;

    if (distFromStart[node1] != std::numeric_limits<int>::max()
        && distFromNode1[node2] != std::numeric_limits<int>::max()
        && distFromNode2[N] != std::numeric_limits<int>::max())
        path1 = (long long)distFromStart[node1] + distFromNode1[node2] + distFromNode2[N];

    if (distFromStart[node2] != std::numeric_limits<int>::max()
        && distFromNode2[node1] != std::numeric_limits<int>::max()
        && distFromNode1[N] != std::numeric_limits<int>::max())
        path2 = (long long)distFromStart[node2] + distFromNode2[node1] + distFromNode1[N];

    long long result = -1;
    if (path1 != -1 && path2 != -1) result = min(path1, path2);
    else if (path1 != -1) result = path1;
    else result = path2;

    cout << result;
    
    return 0;  
}