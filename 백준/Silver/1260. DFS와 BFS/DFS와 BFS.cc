#include <iostream>  
#include <vector>  
#include <queue>

using namespace std;

void DFS(vector<vector<bool>>& vec, vector<bool>& isVisited, int depart, vector<int>& ret)
{
    ret.push_back(depart);
    isVisited[depart] = true;

    for (int next = 1; next < vec[depart].size(); next++)
    {
        if (vec[depart][next] == false) continue;
        if (isVisited[next] == true) continue;

        DFS(vec, isVisited, next, ret);
    }
}

void BFS(vector<vector<bool>>& vec, vector<bool>& isVisited, int depart, vector<int>& ret)
{
    ret.push_back(depart);
    isVisited[depart] = true;

    queue<int> q;
    q.push(depart);

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (int next = 1; next < vec[current_node].size(); next++)
        {
            if (!vec[current_node][next]) continue;
            if (isVisited[next]) continue;

            isVisited[next] = true;
            q.push(next);
            ret.push_back(next);
        }
    } 
}

int main() {  

    ios::sync_with_stdio(false);  
    cin.tie(nullptr);  

    int n, m, v;

    cin >> n >> m >> v;

    vector<vector<bool>> vec(n + 1, vector<bool>(n + 1, false));
    vector<bool> isVisited(n + 1, false);

    while (m--)
    {
        int s, d;
        cin >> s >> d;

        vec[s][d] = true;
        vec[d][s] = true;
    }

    vector<int> ret;

    DFS(vec, isVisited, v, ret);

    for (auto i : ret)
    {
        cout << i << " ";
    }
    cout << '\n';

    ret.clear();
    isVisited = vector<bool>(n + 1, false);
    
    BFS(vec, isVisited, v, ret);

    for (auto i : ret)
    {
        cout << i << " ";
    }

    return 0;  
}