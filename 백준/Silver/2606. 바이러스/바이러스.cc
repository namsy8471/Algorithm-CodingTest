#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

void CheckVirus(set<int>& getVirus, vector<vector<int>>& networks)
{
    queue<int> q;
    q.push(1);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        for (auto connected : networks[n])
        {
            if (getVirus.find(connected) == getVirus.end()) {
                getVirus.insert(connected);
                q.push(connected);
            }
        }
    }
}

int main() {
   
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> networks(n + 1);
    set<int> getVirus;

    getVirus.insert(1);

    for (int i = 0; i < m; i++)
    {
        int a, b;

        cin >> a >> b;
        
        networks[a].push_back(b);
        networks[b].push_back(a);
    }

    CheckVirus(getVirus, networks);

    cout << getVirus.size() - 1;

    return 0;
}


