#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    int nodeCnt;
    cin >> nodeCnt;

    vector<vector<int>> v(nodeCnt + 1, vector<int>());
    vector<int> rootNode(nodeCnt + 1, -1);
    
    for (int i = 0; i < nodeCnt - 1; i++)
    {
        int n, m;

        cin >> n >> m;

        v[n].push_back(m);
        v[m].push_back(n);
    }

    queue<int> q;
    rootNode[1] = 0;
    q.push(1);
    
    while (!q.empty())
    {
        int currentNode = q.front();
        q.pop();

        for (auto& node : v[currentNode]) {
            if (rootNode[node] == -1) {
                rootNode[node] = currentNode;
                q.push(node);
            }
        }
        
    }

    for (int i = 2; i < rootNode.size(); i++)
        cout << rootNode[i] << '\n';

    return 0;  
}